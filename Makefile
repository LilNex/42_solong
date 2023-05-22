# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 17:56:23 by ichaiq            #+#    #+#              #
#    Updated: 2023/05/22 01:06:11 by ichaiq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
HDRS = so_long.h
SOURCES = so_long.c
LIB = libft/libft.a
GNL = gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c
# GNL= gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c
SRC = so_long.c assets/assets.c assets/map.c assets/map_validator.c
	

OBJECTS = $(SRC:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME) so_long.h

$(LIB):
	make -C libft 
	make clean

$(NAME) : $(OBJECTS) $(LIB) $(GNL)
	$(CC) $(CFLAGS) $^ -o $@ 


# build: so_long.h
# 	cd $(LIB) && make bonus
# 	cp $(LIB)libft.a .
# 	gcc $(SRC) $(GNL) libft.a $(CFLAGS) -o $(NAME)
# 	# clear

%.o: %.c $(LIB)
	$(CC) -c $< -o $@ $(CFLAGS) 


clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re run 