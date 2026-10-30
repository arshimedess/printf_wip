/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:37:17 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/30 18:52:08 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

//macro fd?
// write and count = wnc

int	ft_printf(const char *format, ...);
int	wnc_char(char c);
int	wnc_nbr(long n, char *s);
int	wnc_str(char *s);
int	wnc_ptr(void *s);
int	str_len(char *s);

#endif