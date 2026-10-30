/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wnc.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:35:01 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/30 17:32:23 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int str_len(char *s)
{
	int len;

	len = 0;
	while(s[len] != '\0')
	{
		len++;
	}
	return(len);
}

int	wnc_char(char c)
{
	write (1, &c, 1);
	return(1);
}
int	wnc_str(char *s)
{
	int	count;

	if (s == NULL)
	{	
		write (1, "(null)", 6);
		return(6);
	}
	count = 0;
	while (s[count] != '\0')
	{
		write (1, &s[count], 1);
		count++;
	}
	return(count);
}

int wnc_ptr(void *s)
{
	int count;

	write (1, "0x", 2);
	count = 2;
	while (s)
	{
		count += wnc_nbr((unsigned long)s, "0123456789abcdef");
	}
	return(count);
// similar to the wnc str, but needs to put 0x in front and its base 16	
// so you can use wnc_nbr with base 16 in here, it's a mix of str and nbr!
}

int	wnc_nbr(long n, char *s)
{
	int		base;
	int		count;

	base = strlen(s);
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		count++;
	}
	if (n < base)
	{
		write(1, &s[n], 1);
		count++;
	}
	else
	{
		count += wnc_nbr(n / base, s);
		count += wnc_nbr(n % base, s);
	}
	return(count);
}

// we have to cover base 10, and base 16
// base 16 dictionary is:	"0123456789abcdef"
//							"0123456789ABCDEF"

// write putnbr without recursion,