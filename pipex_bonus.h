/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:06:31 by bikourar          #+#    #+#             */
/*   Updated: 2024/03/31 01:49:24 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_pi_pe
{
	int				index;
	int				infile;
	int				outfile;
	char			*path;
	char			**cmd;
	struct s_pi_pe	*next;
}	t_pipe;
t_pipe	*create_pipe(t_pipe **node, int ac, char **av);
t_pipe	*create_linked_list(char *paht, char **command, int indic);
t_pipe	*here_doc(t_pipe **node, int ac, char **av);
void	excute_command(t_pipe **_data, char **en_va);
void	free__linked_(t_pipe **lst);
void	ft_lstadd_back(t_pipe **lst, t_pipe *new);
void	run_childp(t_pipe *node, char **en_var);
void	free_array(char **argement);
void	free_linked(t_pipe **lst);
void	close_file(t_pipe **list);
char	*f_strjoin(char *str1, char *str2, int line_b);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*return_paht(char *arg_v, char **en_va);
char	**return_command(char *command, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char const *src);
char	*free_line(char *back_buf);
char	*start(char *arr, int fd);
char	*get_next_line(int fd);
char	*by_line(char *str);
char	*f_insial(void);
char	spar(char *str);
int		ft_strcmp(char	const *s1, char const *s2);
int		count_word(char const *string, char c);
int		check_nl(char const *str);
size_t	ft_strlen(const char *theString);

#endif