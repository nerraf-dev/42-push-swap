# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:36:23 by sfarren           #+#    #+#              #
#    Updated: 2025/03/25 11:18:08 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    CC = gcc
else
    CC = clang
endif

CFLAGS = -Wall -Wextra -Werror -g

# --- Mandatory (push_swap) ---
NAME = push_swap
LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  src/push_swap.c \
		src/utils.c \
		src/parsing/parsing.c \
		src/parsing/parser_utils.c \
		src/parsing/parser_helpers.c \
		src/init/init_stack.c \
		src/init/init_utils.c \
		src/init/init_b_a.c \
		src/sort/sort_utils.c \
		src/sort/sort_small.c \
		src/sort/sort_big.c \
		src/sort/sort_big_utils.c \
		src/sort/sort_radix.c \
		src/stack/move_to_top.c \
		src/stack/push.c \
		src/stack/rotate.c \
		src/stack/reverse_rotate.c \
		src/stack/stack_utils.c \
		src/stack/swap.c \
		src/ranking/ranking.c \

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# --- Bonus (checker) ---
BONUS_NAME = checker
GNL_DIR = src/gnl
GNL = $(GNL_DIR)/libgnl.a  # Assuming GNL compiles to libgnl.a

BONUS_SRCS = src/checker_bonus.c \
             src/stack/push.c \
             src/stack/rotate.c \
             src/stack/reverse_rotate.c \
             src/stack/swap.c \
             src/stack/stack_utils.c \

BONUS_OBJS = $(BONUS_SRCS:src/%.c=$(OBJ_DIR)/%.o)

# --- Rules ---
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(GNL) $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBFT) $(GNL)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) "3 2 1 0"

.PHONY: all bonus clean fclean re valgrind
