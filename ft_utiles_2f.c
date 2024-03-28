/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_2f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:44 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/27 15:07:48 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strchr(const char *s, int c)
{
	char	*dst;
	char	c1;
	int		i;

	i = 0;
	c1 = (char )c;
	dst = (char *)s;
	while (dst[i] != '\0' && dst[i] != c1)
		i++;
	if (dst[i] == c1)
	{
		dst = (char *)(s + i);
		return (dst);
	}
	return (0);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
		return (ft_strdup(""));
	else if (len > j - start)
		len = j - start;
	d = (char *) malloc (len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
		d[i++] = *((char *)s + start++);
	d[i] = '\0';
	return (d);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (free((char *)s1), NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] != '\0')
	{
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
	}
	return (ft_substr(s1, start, (end - start)));
}
