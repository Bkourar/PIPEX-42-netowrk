/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_paht.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:45:34 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 00:48:00 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_phat(char *argement)
{
	
	if (access(argement, F_OK) == 0 && access(argement, X_OK) == 0)
		return (ft_strdup(argement));
	return (ft_strdup(argement));
}

static char	*return_p1(char *arg, char **en_v)
{
	char	**phat;
	char	**spli;
	char	*contact;
	int		i;

	i = 0;
	while (en_v && en_v[i] && ft_strcmp(en_v[i], "PATH"))
		i++;
	if (!en_v[i] || !en_v || !(*en_v))
		return (puts_error1(en_v, i, arg), NULL);
	phat = ft_split(*(en_v + i) + 5, ':');
	spli = ft_split(arg, ' ');
	i = 0;
	contact = NULL;
	while (phat && phat[i] && spli && (*spli))
	{
		(free(contact) , contact = NULL);
		contact = ft_strjoin(phat[i], *spli);
		if (!access(contact, F_OK) && !access(contact, X_OK))
			break ;
		(i++);
	}
	return (free_array(phat), free_array(spli), contact);
}

static char	*to_merge(char *string, char *str)
{
	char	*contact;

	contact = ft_strtrim(string, " ");
	if (!contact)
		return (NULL);
	contact = ft_strjoin(str, contact);
	if (!contact)
		return (NULL);
	return (contact);
}

static char	*return_p2(char *arg, char **en_v, char c)
{
	char	**phat;
	char	**spli;
	char	*arry;
	int		i;

	i = 0;
	while (en_v && en_v[i] && ft_strcmp(en_v[i], "PATH"))
		i++;
	if (!en_v[i] || !en_v || !(*en_v))
		return (puts_error1(en_v, i, arg), NULL);
	phat = ft_split(*(en_v + i) + 5, ':');
	spli = ft_split(arg, c);
	i = 0;
	arry = NULL;
	while (phat && phat[i] && spli && (*spli))
	{
		(free(arry), arry = NULL);
		arry = to_merge(spli[0], phat[i]);
		if (!arry)
			return (free_array(phat), free_array(spli), NULL);
		if (!access(arry, F_OK) && !access(arry, X_OK))
			break ;
		 i++;
	}
	return (free_array(phat), free_array(spli), arry);
}

char	*return_paht(char *arg_v, char **en_va)
{
	static int i;
	char	c;

	i++;
	c = spar(arg_v);
	if (!ft_strcmp(arg_v, ""))
		return (ft_strdup(""));
	if (!ft_strcmp(arg_v, " "))
		return (ft_strdup(" "));
	if (arg_v[0] == '/')
		return (check_phat(arg_v));
	else if (c == ' ')
		return (return_p1(arg_v, en_va));
	if (c == '\'' || c == '\"')
		return (return_p2(arg_v, en_va, spar(arg_v)));
	return (NULL);
}
