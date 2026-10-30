/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:38:18 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/30 19:04:45 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wnc_method(const char n, va_list *ap)
{
	if (n == 'c')
		return (wnc_char(va_arg(*ap, int)));
	else if (n == '%')
		return (wnc_char('%'));
	else if (n == 's')
		return (wnc_str(va_arg(*ap, char *)));
	else if (n == 'p')
		return (wnc_ptr(va_arg(*ap, void *)));
	else if (n == 'd' || n == 'i')
		return (wnc_nbr(va_arg(*ap, int), "0123456789"));
	else if (n == 'u')
		return (wnc_nbr(va_arg(*ap, unsigned int), "0123456789"));
	else if (n == 'x')
		return (wnc_nbr(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (n == 'X')
		return (wnc_nbr(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	return (0);
}

static int	check_spec(const char n, va_list *ap)
{
	char	*specs;
	int		count;
	int		i;

	count = 0;
	specs = "cspdiuxX%";
	i = 0;
	while (specs[i] != '\0')
	{
		if (specs[i] == n)
			count += wnc_method(n, ap);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		count = 0;
		if (format[i] == '%')
		{
			count += check_spec(format[i + 1], &ap);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end (ap);
	return (count);
}

//"sth sth %" ? then format[i + 1] will give seg fault. we need to fixit

// int	main(void)
// {
//    char *s;
//    int a = 9991786;

//    printf("Original:: %% %c %s %p %d %i %u %x %X\n",'a',
// "A string",&s,a,a,a,a,a);
//    ft_printf("Mine:::::: %% %c %s %p %d %i %u %x %X\n",'a',
// "A string",&s,a,a,a,a,a);
// 	return (0);
// }
