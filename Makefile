# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2024/10/17 19:37:03 by sfarren          ###   ########.fr        #
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


SRCS =  src/main.c \
		src/stack_ops/parsing.c \
		src/stack_ops/stack_init.c \
		src/stack_ops/stack_ops.c \
		src/stack_ops/validation.c \
		src/sort/push.c \
		src/sort/rotate.c \
		src/sort/reverse_rotate.c \
		src/sort/swap.c \
		src/sort/sort_small.c \
		src/sort/sort_utils.c \

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
