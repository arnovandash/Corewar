# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/09/04 12:35:28 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
LIBFTL		=	-L libft -lft
LIBFTI		=	-I libft/includes
INCLUDE		=	-I includes $(LIBFTI)
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDE)
LFLAGS		=	$(INCLUDE) $(LIBFTL)
CC			=	gcc
LD			=	gcc 
INC			=	includes/corewar.h			\
				includes/op.h

SRC			=	srcs/destroy_process.c		\
				srcs/dump_memory.c			\
				srcs/error_quit.c			\
				srcs/free_env.c				\
				srcs/ft_add.c				\
				srcs/ft_aff.c				\
				srcs/ft_and.c				\
				srcs/ft_fork.c				\
				srcs/ft_live.c				\
				srcs/ft_load.c				\
				srcs/ft_load_index.c		\
				srcs/ft_long_fork.c			\
				srcs/ft_long_load.c			\
				srcs/ft_long_load_index.c	\
				srcs/ft_or.c				\
				srcs/ft_store.c				\
				srcs/ft_store_index.c		\
				srcs/ft_sub.c				\
				srcs/ft_xor.c				\
				srcs/ft_zjmp.c				\
				srcs/get_arg_len.c			\
				srcs/get_dir.c				\
				srcs/get_indir.c			\
				srcs/get_indir_long.c		\
				srcs/get_reg.c				\
				srcs/init_env.c				\
				srcs/init_functions.c		\
				srcs/load_arena.c			\
				srcs/loop_mem.c				\
				srcs/main.c					\
				srcs/manage_args.c			\
				srcs/op.c					\
				srcs/pc_pos.c				\
				srcs/read_programs.c		\
				srcs/run_process.c			\
				srcs/run_simulation.c

OBJ			=	$(SRC:srcs/%.c=build/%.o)

all: lft assembler corewar

build/%.o: srcs/%.c $(INC)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

corewar: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

assembler:
	@make -s -C Assembler all

lft:
	@make -s -C libft all

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build
	@make -s -C libft clean
	@make -s -C Assembler clean

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make -s -C libft fclean
	@make -s -C Assembler fclean

test:
	@if [ $TERM_PROGRAM = "Apple_Terminal" -o $TERM_PROGRAM = "iTerm.app" ];\
		then echo "True";\
		else echo "False"; echo $TERM;\
	fi;

re: fclean all
