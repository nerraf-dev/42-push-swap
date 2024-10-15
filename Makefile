# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2024/10/15 13:51:47 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S), Darwin) # macOS
# 	CC = gcc
# else
# 	CC = clang # Default to clang for other systems, including 42's
# endif
CC = gcc
# TODO: remove -g flag
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS += -Wl,--preload=/usr/lib/valgrind/libasan.so

NAME = push_swap
LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a

COUNT_SORT = src/ranking

SRCS =  src/ranking/ranking.c src/ranking/ranking_utils.c \
		src/stack_ops/swap.c src/stack_ops/rotate.c src/stack_ops/reverse_rotate.c \
		src/sort/sort_small.c \
		src/push_swap.c \
		src/push_swap_utils.c \
		src/main.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
