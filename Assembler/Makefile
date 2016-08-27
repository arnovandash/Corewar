# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/08/27 09:37:45 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Assembler

CC=clang

CFLAGS=-Wall -Wextra -Werror -g

RM=rm -f

INC_LIBFT= -L libft/ -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/ -I ./libft/includes 

SRC = $(PATH_SRC)main.c $(PATH_SRC)ft_error.c $(PATH_SRC)ft_list.c \
	  $(PATH_SRC)ft_misc_one.c $(PATH_SRC)op.c $(PATH_SRC)ft_list_cmd.c \
	  $(PATH_SRC)ft_misc_two.c $(PATH_SRC)ft_read_check.c \
	  $(PATH_SRC)ft_read_file.c $(PATH_SRC)ft_validate.c \
	  $(PATH_SRC)ft_val_label.c $(PATH_SRC)ft_is_valid.c $(PATH_SRC)ft_print.c \
	  $(PATH_SRC)ft_print_name.c $(PATH_SRC)ft_print_cmds.c \
	  $(PATH_SRC)ft_print_params.c $(PATH_SRC)ft_print_lbl.c \
	  $(PATH_SRC)ft_check_digit.c

OBJ = main.o ft_error.o ft_list.o ft_misc_one.o op.o ft_list_cmd.o \
	  ft_misc_two.o ft_read_check.o ft_read_file.o ft_validate.o \
	  ft_val_label.o ft_is_valid.o ft_print.o ft_print_name.o ft_print_cmds.o \
	  ft_print_params.o ft_print_lbl.o ft_check_digit.o

$(NAME):
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) 
	@echo "Compilation was successful!"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) 
	@echo "Compilation was successful!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

norme:
	@clear
	@norminette $(SRC)

re: fclean all
