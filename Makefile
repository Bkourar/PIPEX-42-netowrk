NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = pipex.c ft_split.c ft_utiles_2f.c ft_utiles_f.c ft_parse_paht.c ft_clean_file.c \
		ft_parse_command.c ft_creat_linked_list.c ft_creat_pipe.c \
		ft_excute_shell_command.c
SRCS_BONUS = pipex_bonus.c ft_creat_pipe.c ft_excute_shell_command.c \
		ft_split.c ft_creat_linked_list.c ft_here_doc.c ft_clean_file.c ft_parse_command.c \
		get_next_line.c get_next_utiles.c ft_utiles_2f.c ft_utiles_f.c ft_parse_paht.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
CC = cc
RED = \033[0;31m
GREEN = \033[0;32m

all 			: $(NAME)

$(NAME)			: $(OBJS) pipex.h
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)make pipex"

bonus			: $(NAME_BONUS)

$(NAME_BONUS)	: $(OBJS_BONUS) pipex_bonus.h
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)make pipex_bonus"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)clean pipex"

clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)

re : fclean $(NAME)

.PHONY : all clean fclean re