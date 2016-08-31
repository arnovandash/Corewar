# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/26 18:13:07 by adippena          #+#    #+#              #
#    Updated: 2016/08/29 09:13:20 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
INCLUDE	=	-I includes
CFLAGS	=	-Wall -Wextra -Werror -Ofast -Wno-unused-result

INC		=	$(shell find includes -name "*.h")
SRC		=	$(shell find srcs -name "*.c")
OBJ		=	$(SRC:srcs/%.c=build/%.o)

all: $(NAME)

build/%.o: srcs/%.c $(INC)
	@echo "\033[94mLFT CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[94mLFT AR    $@\033[0m"
	@ar cr $@ $^
	@ranlib $@

clean:
	@echo "\033[94mLFT RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[94mLFT RM    $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all
