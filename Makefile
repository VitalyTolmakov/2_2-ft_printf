# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 16:11:24 by fheidi            #+#    #+#              #
#    Updated: 2021/12/18 14:01:53 by fheidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
RC = ar rc
RL = ranlib
CFLAGS = -Wall -Werror -Wextra -c
SRC = ft_printf_utils.c ft_printf.c
OBJ = $(SRC:.c=.o)
HEADERS = ft_printf.h
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(RC) $(NAME) $(OBJ)
	$(RL) $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)


fclean: clean
	$(RM) $(NAME)

re: fclean all

n:
	norminette -R CheckForbiddenSourceHeader ./*.c

def:
	norminette -R CheckDefine ./*.h

.PHONY: all clean fclean re n def
