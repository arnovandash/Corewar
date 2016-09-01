# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/09/01 12:19:21 by rojones          ###   ########.fr        #
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

INC			=	$(shell find includes -name "*.h")
SRC			=	$(shell find srcs -name "*.c")
OBJ			=	$(SRC:srcs/%.c=build/%.o)

all: lft corewar

build/%.o: srcs/%.c $(INC)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

corewar: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

lft:
	@make -s -C libft all

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build
	@make -s -C libft clean

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make -s -C libft fclean

test:
	@if [ $TERM_PROGRAM = "Apple_Terminal" -o $TERM_PROGRAM = "iTerm.app" ];\
		then echo "True";\
		else echo "False"; echo $TERM;\
	fi;

re: fclean all
