/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:08:18 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 00:33:03 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**return_command(char *command, char c)
{
	char	**spli;
	char	*strim;

	spli = ft_split(command, c);
	if (!spli || !(*spli))
	{
		if (!(*spli))
			spli[0] = NULL;
		return (spli);
	}
	strim = ft_strtrim(spli[0], " ");
	if (!strim)
		return (free_array(spli), NULL);
	free(spli[0]);
	spli[0] = strim;
	return ((spli));
}
