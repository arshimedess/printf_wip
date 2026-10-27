/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wnc_str.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:18:50 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/27 20:27:35 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wnc_str(char *s)
{
	int	i;

	if (s == NULL)
		write (1, '(null)', 6);
	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return(i);
}
