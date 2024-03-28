/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excute_shell_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:13:17 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/27 21:18:31 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	my_close(int fd)
{
	if (close(fd) < 0)
		return (write(2, "permission denied:\n", 20), 1);
	return (0);
}

void	run_childp(t_pipe *node, char **en_var)
{
	int	id;

	id = fork();
	if (id == -1)
		(perror("errno"), close_file(&node), free_linked(&node), exit(2));
	if (id == 0)
	{
		close_file(&node->next);
		dup2(node->infile, STDIN_FILENO);
		if (my_close(node->infile) < 0)
			(close_file(&node), free_linked(&node), exit(2));
		dup2(node->outfile, STDOUT_FILENO);
		if (my_close(node->outfile) < 0)
			(close_file(&node), free_linked(&node), exit(2));
		puts("dsfjldl");
		if (execve(node->path, node->cmd, en_var) < 0)
			(write(2, "command not found: ", 20),
				write(2, node->path, ft_strlen(node->path)), write(2, "\n", 1)
				, close_file(&node), free_linked(&node), exit(2));
	}
	if (my_close(node->infile) < 0)
		(close_file(&node), free_linked(&node), exit(2));
	if (my_close(node->outfile) < 0)
		(close_file(&node), free_linked(&node), exit(2));
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
