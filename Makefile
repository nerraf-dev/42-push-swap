# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2024/10/25 12:41:22 by sfarren          ###   ########.fr        #
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

        # src/init/validate_args.c \
        # src/init_a_b.c \
        # src/init_b_a.c \
        # src/push_swap.c \
        # src/sort/move_a_to_b.c \
        # src/sort/push.c \
        # src/sort/rotate.c \

        # src/sort/swap.c \
        # src/sort/move_utils.c \
        # src/sort/reverse_rotate.c \
        # src/sort/sort_big.c \
        # src/sort/sort_utils.c \
        # src/stack_ops/parsing.c \
        # src/stack_ops/stack_init.c \
        # src/stack_ops/stack_ops.c \
        # src/stack_ops/validation.c

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
