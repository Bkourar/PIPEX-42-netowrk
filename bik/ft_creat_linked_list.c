/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:11:13 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/27 22:43:57 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*head;

	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		head = (*lst);
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}

t_pipe	*create_linked_list(char *paht, char **command, int indic)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	if (!node)
		return (NULL);
	node->index = indic;
	node->infile = 0;
	node->outfile = 1;
	node->path = paht;
	node->cmd = command;
	node->next = NULL;
	return (node);
}
