/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:35:44 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/28 00:46:07 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipe	*pars(int ac1, char **av1, char **env1)
{
	t_pipe	*node;
	t_pipe	*tmp;
	char	*paht;
	char	**command;
	int		i;

	i = 1;
	node = NULL;
	tmp = NULL;
	while (++i < ac1 - 1)
	{
		paht = return_paht(av1[i], env1);
		if (!paht)
			return (free_linked (&node), NULL);
		command = return_command(av1[i], spar(av1[i]));
		if (!command)
			return (free(paht), NULL);
		tmp = create_linked_list(paht, command, i - 2);
		ft_lstadd_back(&node, tmp);
	}
	return (node);
}

void	lol()
{
	system("leaks pipex");
}
int	main(int ac, char **av, char **env)
{
	t_pipe	*pipe;
	
	atexit(lol);
	if (ac == 5)
	{
		pipe = pars(ac, av, env);
		if (!pipe)
			return (free_linked(&pipe), 1);
		pipe = create_pipe(&pipe, ac, av);
		if (!pipe)
			return (free_linked(&pipe), 1);
		excute_command(&pipe, env);
	}
	else
		write (2, "nombre d'argument invalide\n", 27);
}
