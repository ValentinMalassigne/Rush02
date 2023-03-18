# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 12:04:44 by liguyon           #+#    #+#              #
#    Updated: 2023/03/18 12:27:53 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= rush-02

# Sources
SRC		:= 	main.c \

# Includes
INCLUDE		:= rush02.h

# Compiler
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

# Objects
OBJ		= $(SRC:.c=.o)


# Targets
$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

all:		$(NAME)

%.o:		%.c $(INCLUDE)
		$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
