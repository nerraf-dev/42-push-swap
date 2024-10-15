# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 18:34:39 by sfarren           #+#    #+#              #
#    Updated: 2024/09/20 11:41:41 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME = libftprintf.a

# Compiler and Flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
	CC = gcc
else
	CC = clang # Default to clang for other systems, including 42's
endif

CFLAGS = -Wall -Wextra -Werror

# Source and Object Files
SRC = 	ft_printchr.c \
		ft_printf.c \
		ft_printptr.c \
		ft_printstr.c \
		ft_printnbr_base.c \

OBJS = $(SRC:.c=.o)

# libft Configuration
LIBFT_DIR = ../
LIBFT = $(LIBFT_DIR)/libft.a

# Include Directories
INCLUDES = -I./ -I$(LIBFT_DIR)

.PHONY: all clean fclean re libft

# Default Rule
all: libft $(NAME)

# Rule for Making libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Rule for Making the Project
$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

# Compiling Object Files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Objects
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Full Clean
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Re-make
re: fclean all
