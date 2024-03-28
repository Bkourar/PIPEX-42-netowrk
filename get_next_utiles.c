/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:15 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/27 15:47:43 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_nl(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*f_strjoin(char *str1, char *str2, int line_b)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	dest = (char *)malloc (ft_strlen(str1) + line_b + 1);
	if (!dest || !str2)
		return (free(str1), str1 = NULL, NULL);
	while (str1[++i])
		dest[i] = str1[i];
	while (++j < line_b)
		dest[i + j] = str2[j];
	dest[i + j] = '\0';
	return (free(str1), dest);
}

char	*free_line(char *back_buf)
{
	char	*next_buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!back_buf)
		return (NULL);
	while (back_buf[i] && back_buf[i] != '\n')
		i++;
	if (back_buf[i] == '\n')
		i++;
	while (back_buf[i + j])
		j++;
	next_buf = (char *) malloc(j + 1);
	if (!next_buf)
		return (free(back_buf), back_buf = NULL, NULL);
	j = 0;
	while (back_buf[i])
		next_buf[j++] = back_buf[i++];
	next_buf[j] = '\0';
	free (back_buf);
	if (*next_buf == '\0')
		return (free(next_buf), next_buf = NULL, NULL);
	return (next_buf);
}
