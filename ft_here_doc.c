/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:47:34 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 17:11:32 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	file_d1(char *name, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			(write(2, "fail open\n", 10), exit(1));
		return (fd);
	}
	return (open(name, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

static int	long_nl(char const *str, char del)
{
	int	i;

	i = 0;
	while (str[i] != del && str[i])
		i++;
	return (i);
}

static int	str_cmp(char *buf, char *limiter)
{
	int	a;

	a = 0;
	while (buf[a] && buf[a] != '\n' && limiter[a] && limiter[a] == buf[a])
		a++;
	if (long_nl(limiter, '\0') == long_nl(buf, '\n')
		&& long_nl(limiter, '\0') == a)
		return (1);
	return (0);
}

static void	manipilation_hdc(char **buffer, char *limiter, int *std_o)
{
	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		*buffer = get_next_line(0);
		if (!*buffer)
			break ;
		if (str_cmp(*buffer, limiter))
			break ;
		write(*std_o, *buffer, long_nl(*buffer, '\n') + 1);
		free(*buffer);
	}
	free(*buffer);
	close(*std_o);
}

t_pipe	*here_doc(t_pipe **node, int ac, char **av)
{
	t_pipe	*temp;
	char	*buf;
	int		fd[2];
	int		fd_1[2];

	temp = (*node);
	while (temp->next)
	{
		if (pipe(fd) < 0)
			(free(temp), free(temp->next), exit(1));
		if (temp->index == 0)
		{
			if (pipe(fd_1) < 0)
				(free(temp), free(temp->next), exit(1));
			manipilation_hdc(&buf, av[2], &fd_1[1]);
			temp->infile = fd_1[0];
		}
		temp->outfile = fd[1];
		temp->next->infile = fd[0];
		temp = temp->next;
	}
	temp->outfile = file_d1(av[ac - 1], 1);
	return (*node);
}
