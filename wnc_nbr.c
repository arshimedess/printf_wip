/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wnc_nbr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:29:52 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/27 20:27:28 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// needs to write it with no RECURSION so we can count!

#include "ft_printf.h"

int	wnc_nbr(int n)
{
	int		num;
	int		base;
	long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = tmp * -1;
	}
	if (tmp >= 0 && tmp <= 9)
	{
		num = tmp + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr_fd(tmp / 10, 1);
		ft_putnbr_fd(tmp % 10, 1);
	}
}



// we have to cover base 10, and base 16
// base 16 dictionary is:	"0123456789abcdef"
//							"0123456789ABCDEF"