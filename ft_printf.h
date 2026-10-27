/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:37:17 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/27 16:19:25 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>

//macro fd?

int	printf(const char * format, ... );
void	wnc_char(char c, int fd);
void	wnc_nbr(int n, int fd);
void	wnc_str(char *s, int fd);

#endif