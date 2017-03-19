# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:14:57 by cnovo-ri          #+#    #+#              #
#    Updated: 2017/03/16 17:53:47 by cnovo-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=GNL

SRC=get_next_line.c main.c

LIB=./libft/libft.a

OBJ=$(SRC:.c=.o)

FLAG=-Wall Wextra -Werror

CC=cc

all: $(NAME)

$(NAME): $(LIB)
	@$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)  -L ./libft -lft
	@echo "\033[1m\033[32m[ ✔ ]Compiled :\033[0m $(NAME) ࿇"

$(LIB):
	@make re -C ./libft

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(OBJ) ࿇"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(NAME) ࿇"

re: fclean all

.PHONY: all clean fclean re
