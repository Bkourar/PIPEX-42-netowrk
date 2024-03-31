/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:04 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 01:53:07 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_pipe	*pars(int ac1, char **av1, char **env1, int j)
{
	t_pipe	*node;
	t_pipe	*tmp;
	char	*paht;
	char	**command;
	int		i;

	i = j + 1;
	node = NULL;
	tmp = NULL;
	while (++j < ac1 - 1)
	{
		paht = return_paht(av1[j], env1);
		command = return_command(av1[j], spar(av1[j]));
		tmp = create_linked_list(paht, command, j - i);
		ft_lstadd_back(&node, tmp);
	}
	return (node);
}

void f()
{
	system("leaks pipex_bonus");
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipe;

	atexit(f);
	if (ac == 6 && !ft_strcmp(av[1], "here_doc"))
	{
		pipe = pars(ac, av, env, 2);
		if (!pipe)
			return (free_linked(&pipe), 1);
		pipe = here_doc(&pipe, ac, av);
		if (!pipe)
			return (free_linked(&pipe), 1);
		excute_command(&pipe, env);
	}
	else if (ac >= 5)
	{
		pipe = pars(ac, av, env, 1);
		if (!pipe)
			return (free_linked(&pipe), 1);
		pipe = create_pipe(&pipe, ac, av);
		if (!pipe)
			return (free_linked(&pipe), 1);
		excute_command(&pipe, env);
	}
	else
		return (write (2, "nombre d'argument invalide\n", 27), 1);
	free_linked(&pipe);
}
