# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2024/10/26 13:10:17 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
	CC = gcc
else
	CC = clang # Default to clang for other systems, including 42's
endif
# TODO: remove -g flag
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS += -Wl,--preload=/usr/lib/valgrind/libasan.so

NAME = push_swap
LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a


SRCS =  src/push_swap.c \
        src/init/parsing.c \
        src/init/parser_utils.c \
        src/init/init_stack.c \
        src/sort/sort_utils.c \
		src/sort/sort_small.c \
		src/sort/sort_big.c \
        src/stack/stack_utils.c \
        src/stack/push.c \
        src/stack/rotate.c \
        src/stack/swap.c \
        src/stack/reverse_rotate.c \
		src/stack/init_a_b.c \
		src/stack/init_b_a.c \


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
