# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2025/03/17 12:39:13 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CC = gcc
else
	CC = clang
endif

CFLAGS = -Wall -Wextra -Werror -g


NAME = push_swap
LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  src/push_swap.c \
		src/parsing/parsing.c \
		src/parsing/parser_utils.c \
		src/parsing/parser_helpers.c \
		src/init/init_stack.c \
		src/init/init_a_b.c \
		src/init/init_b_a.c \
		src/sort/sort_utils.c \
		src/sort/sort_small.c \
		src/sort/sort_big.c \
		src/sort/sort_radix.c \
		src/stack/stack_utils.c \
		src/stack/push.c \
		src/stack/rotate.c \
		src/stack/swap.c \
		src/stack/reverse_rotate.c \
		src/ranking/ranking.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)


$(NAME)_valgrind: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) "3 2 1 0"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./$(NAME) "3 2 1 0"

re: fclean all

.PHONY: all clean fclean re valgrind
