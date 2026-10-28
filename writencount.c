/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writencount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:35:01 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/28 17:50:33 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wnc_char(char c)
{
	write (1, &c, 1);
	return(1);
}
int	wnc_str(char *s)
{
	int	i;

	if (s == NULL)
	{	
		write (1, "(null)", 6);
		return(6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return(i);
}
int	wnc_nbr(int n)
{
	int		num;
	int		base;
	long	tmp;
	int		count;

	if (base == 10);
	
	count = 0;
	tmp = n;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = tmp * -1;
		count += 1;
	}
	if (tmp >= 0 && tmp <= 9)
	{
		num = tmp + '0';
		write(1, &num, 1);
		count++;
	}
	else
	{
		ft_putnbr_fd(tmp / 10, 1);
		ft_putnbr_fd(tmp % 10, 1);
	}
	return(count);
}

// we have to cover base 10, and base 16
// base 16 dictionary is:	"0123456789abcdef"
//							"0123456789ABCDEF"

// write putnbr without recursion,