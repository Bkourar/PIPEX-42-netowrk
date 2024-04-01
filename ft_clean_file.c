/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:43:05 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 07:14:30 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	del(void *p)
{
	t_pipe	*node;

	node = p;
	if (node->path)
		free(node->path);
	if (node->cmd)
		free_array(node->cmd);
}

void	free_linked(t_pipe **lst)
{
	t_pipe	*l;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		del(*lst);
		free(*lst);
		*lst = l;
	}
	*lst = NULL;
}

void	free_array(char **argement)
{
	int	i;

	if (!argement)
		return ;
	i = 0;
	while (argement[i])
	{
		free(argement[i]);
		i++;
	}
	free(argement);
}

void	close_file(t_pipe **list)
{
	t_pipe	*tmp;

	if (!list || !(*list))
		return ;
	tmp = (*list);
	while (tmp)
	{
		if (my_close(tmp->infile) < 0)
			exit(1);
		if (my_close(tmp->outfile) < 0)
			exit(1);
		tmp = tmp->next;
	}
}
