# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 07:37:46 by ghavenga          #+#    #+#              #
#    Updated: 2016/08/26 08:07:12 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= corewar

CC = gcc -o

CFLAGS = -Wall -Werror -Wextra -g3

LIBFT = -L libft/ -lft

HEADER = -I ./includes/ -I ./libft/includes/

SP = ./srcs/

SRC =	$(SP)main.c					\
		$(SP)read_programs.c		\
		$(SP)error_quit.c			\
		$(SP)free_env.c				\
		$(SP)init_env.c				\
		$(SP)pc_pos.c				\
		$(SP)manage_args.c			\
	 	$(SP)run_simulation.c		\
		$(SP)destroy_process.c		\
	 	$(SP)run_process.c			\
		$(SP)ft_aff.c				\
		$(SP)ft_long_fork.c			\
		$(SP)ft_long_load.c			\
		$(SP)ft_long_load_index.c	\
		$(SP)get_param_value.c		\
		$(SP)set_param_value.c		\

all: $(NAME)

$(NAME):
	@make qme
	@clear
	@echo "\x1b[31m-----Compiling Libft\x1b[0m"
	@make -C libft fclean
	@make -C libft
	@echo "\x1b[34m+++++Done Compiling Libft\x1b[0m"
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[34m+++++Done Compiling $(NAME)\x1b[0m"
	@echo "\x1b[32m+++++Completed All Compiling\x1b[0m"

force:
	@if [ -f $(NAME) ]; then \
		make re; else \
		make $(NAME); \
		fi;

quick:
	@clear
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[32m+++++Done Compiling $(NAME)\x1b[0m"

clean:
	@rm $(NAME)
	@echo "\x1b[32m\t+++++Completed Clean\x1b[0m"

fclean: clean
	@make -C libft fclean
	@echo "\x1b[32m\t+++++Completed Full Clean\x1b[0m"

re: fclean all

me:
	@make qme
	@echo "\x1b[32mAuthor:"
	cat -e author

qme:
	@if [ ! -f author ]; then \
		whoami > author; git add author; git commit -m "added author"; \
		git push; \
		fi

norme:
	@clear
	@echo "Starting Norminette, good luck!"
	@norminette $(SRC)
