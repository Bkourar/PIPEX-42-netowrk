/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:06:35 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 03:24:59 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # include "track_leaks.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct pipex
{
	int				index;
	int				infile;
	int				outfile;
	char			*path;
	char			**cmd;
	struct pipex	*next;
}	t_pipe;
t_pipe	*create_pipe(t_pipe **node, int ac, char **av);
t_pipe	*create_linked_list(char *paht, char **command, int indic);
void	excute_command(t_pipe **_data, char **en_va);
void	ft_lstadd_back(t_pipe **lst, t_pipe *new);
void	run_childp(t_pipe *node, char **en_var);
void	free_array(char **argement);
void	free_linked(t_pipe **lst);
void	close_file(t_pipe **list);
void	puts_error1(char **enva, int pos, char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*return_paht(char *arg_v, char **en_va);
char	**return_command(char *command, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char const *src);
char	spar(char *str);
int		ft_strcmp(char	const *s1, char const *s2);
int		count_word(char const *string, char c);
int		my_close(int fd);
size_t	ft_strlen(const char *theString);

#endif