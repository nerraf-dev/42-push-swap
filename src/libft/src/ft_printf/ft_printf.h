/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:20:31 by sfarren           #+#    #+#             */
/*   Updated: 2025/01/08 15:08:38 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft.h"

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# ifdef __APPLE__
#  define NULL_PTR_STR "0x0"
# elif defined(_WIN32)
#  define NULL_PTR_STR "0x0"
# else
#  define NULL_PTR_STR "(nil)"
# endif

/**
 * Prints formatted output to the standard output stream.
 *
 * This function takes a format string `str` and a variable number of arguments,
 * and prints the formatted output to the standard output stream. It supports
 * various format specifiers, such as `%d` for integers, `%s` for strings, etc.
 *
 * @param str The format string specifying the output format.
 * @param ... The variable number of arguments to be formatted and printed.
 * @return total number of chars printed, or a negative value if error occurs.
 */
int		ft_printf(const char *str, ...);

/**
 * Prints formatted output to a file descriptor.
 *
 * This function takes a file descriptor `fd`, a format string `str`, and a
 * variable number of arguments, and prints the formatted output to the
 * specified file descriptor. It supports various format specifiers, such as
 * `%d` for integers, `%s` for strings, etc.
 *
 * @param fd  The file descriptor to which the output should be printed.
 * @param str The format string specifying the output format.
 * @param ... The variable number of arguments to be formatted and printed.
 * @return total number of chars printed, or a negative value if error occurs.
 */
int		ft_printf_fd(int fd, const char *str, ...);

/**
 * Prints a long long integer in a specified base.
 *
 * This function prints the given long long integer `n` in the specified `base`.
 *
 * @param n     The long long integer to be printed.
 * @param base  The string containing the characters used for the base.
 * @param count A pointer to integer that tracks the num of characters printed.
 */
void	ft_printnbr_base(long long n, char *base, int *count);

/**
 * Prints a long long integer in a specified base to a file descriptor.
 *
 * This function prints the given long long integer `n` in the specified `base`
 * to a file descriptor.
 *
 * @param n     The long long integer to be printed.
 * @param base  The string containing the characters used for the base.
 * @param count A pointer to integer that tracks the num of characters printed.
 * @param fd    The file descriptor to which the output should be printed.
 */
void	ft_printnbr_base_fd(long long n, char *base, int *count, int fd);

/**
 * Prints a character.
 *
 * @param c     The character to be printed.
 * @param count keeps track of the number of characters printed.
 */
void	ft_printchr(char c, int *count);

/**
 * Prints a character to a file descriptor.
 *
 * @param c     The character to be printed.
 * @param count keeps track of the number of characters printed.
 * @param fd    The file descriptor to which the character should be printed.
 */
void	ft_printchr_fd(char c, int *count, int fd);

/**
 * Prints a string.
 *
 * @param s     The string to be printed.
 * @param count keeps track of the number of characters printed.
 */
void	ft_printstr(char *s, int *count);

/**
 * Prints a string to a file descriptor.
 *
 * @param s     The string to be printed.
 * @param count keeps track of the number of characters printed.
 * @param fd    The file descriptor to which the string should be printed.
 */
void	ft_printstr_fd(char *s, int *count, int fd);

/**
 * Prints a pointer address.
 *
 * @param ptr   The pointer address to be printed.
 * @param count keeps track of the number of characters printed.
 */
void	ft_printptr(void *ptr, int *count);

/**
 * Prints a pointer address to a file descriptor.
 *
 * @param ptr   The pointer address to be printed.
 * @param count keeps track of the number of characters printed.
 * @param fd    The file descriptor to which the pointer address should be
 *              printed.
 */
void	ft_printptr_fd(void *ptr, int *count, int fd);

// libft
char	*ft_strchr(const char *s, int c);

/**
 * Converts an unsigned integer to a string representation.
 *
 * @param n The unsigned integer to be converted.
 * @return  The string representation of the unsigned integer.
 */
char	*ft_utoa(unsigned int n);

#endif
