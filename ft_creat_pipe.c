/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:08:48 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 17:11:09 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	file_d1(char *name, int mode, t_pipe *node)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
		{
			write(2, "no such file or directory: ", 28);
			(write(2, name, ft_strlen(name)), write(2, "\n", 1));
		}
		return (fd);
	}
	else if (mode == 1)
	{
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			(write(2, "permission denied:\n", 20), close_file(&node),
				free_linked(&node), exit(1));
		return (fd);
	}
	return (0);
}

t_pipe	*create_pipe(t_pipe **node, int ac, char **av)
{
	t_pipe	*tmp;
	int		fd[2];

	tmp = (*node);
	while (tmp->next)
	{
		if (pipe(fd) < 0)
			return (free_linked(node), NULL);
		if (tmp->index == 0)
			tmp->infile = file_d1(av[1], 0, *node);
		tmp->outfile = fd[1];
		tmp->next->infile = fd[0];
		tmp = tmp->next;
	}
	tmp->outfile = file_d1(av[ac - 1], 1, *node);
	return (*node);
}
