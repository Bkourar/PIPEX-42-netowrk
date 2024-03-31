/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excute_shell_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:13:17 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 04:17:51 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	puts_error1(char **enva, int pos, char *str)
{
	if (!enva[pos] || !enva || !(*enva))
	{
		write(2, "command not found: ", 20);
		(write(2, str, ft_strlen(str)), write(2, "\n", 1));
	}
}

static void puts_error(t_pipe *data)
{
	int	i;

	i = 0;
	if (!ft_strcmp(data->path, ""))
	{
		write(2, "permission denied:\n", 20);
		(free_linked(&data), exit(1));
	}
	write(2, "command not found: ", 20);
	while (data->cmd[i])
	{
		write(2, data->cmd[i], ft_strlen(data->cmd[i]));
		write(2, " ", 1);
		i++;
	}
	(write(2, "\n", 1), free_linked(&data), exit(1));
}

int	my_close(int fd)
{
	if (close(fd) < 0)
		return (write(2, "permission denied:\n", 20), 1);
	return (0);
}

void	run_childp(t_pipe *node, char **en_var)
{
	int	id;

	if (node->infile > 0)
		id = fork();
	else
		id = -2;
	if (id == -1)
			(perror("errno"), close_file(&node), free_linked(&node), exit(1));
	if (id == 0)
	{
		close_file(&node->next);
		dup2(node->infile, STDIN_FILENO);
		if (my_close(node->infile) < 0)
			(close_file(&node), free_linked(&node), exit(1));
		dup2(node->outfile, STDOUT_FILENO);
		if (my_close(node->outfile) < 0)
			(close_file(&node), free_linked(&node), exit(1));
		if (!ft_strcmp(node->path, " ") || execve(node->path, node->cmd, en_var) < 0)
			puts_error(node);
	}
	if (node->infile > 0 && node->index == 0 && my_close(node->infile) < 0)
		(close_file(&node), free_linked(&node), exit(1));
	if (my_close(node->outfile) < 0)
		(close_file(&node), free_linked(&node), exit(1));
}

void	excute_command(t_pipe **_data, char **en_va)
{
	t_pipe	*tmp;
	int		i;

	tmp = (*_data);
	i = 0;
	while (tmp)
	{
		run_childp(tmp, en_va);
		tmp = tmp->next;
		i++;
	}
	while (i)
		(wait(NULL), i--);
	free_linked(_data);
}
