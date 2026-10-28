/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:37:17 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/28 16:55:28 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>

//macro fd?
// write and count = wnc

int	printf(const char * format, ... );
int	wnc_char(char c);
int	wnc_nbr(int n);
int	wnc_str(char *s);

#endif