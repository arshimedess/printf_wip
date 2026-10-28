/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:38:18 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/28 18:25:45 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int wnc_method(const char n, va_list *ap)
{
   if (n == 'c')
      return(wnc_char(va_arg(*ap, int)));
   else if (n == '%')
      return(wnc_char('%'));
   else if (n == 's')
      return(wnc_str(va_arg(*ap, char *)));
   else if (n == 'p')
      return(wnc_ptr(va_arg(*ap, void *)));
   else if (n == 'd' || n == 'i')
      return(wnc_nbr(va_arg(*ap, int), "0123456789"));
   else if (n == 'u')
      return(wnc_nbr(va_arg(*ap, unsigned int), "0123456789"));
   else if (n == 'x')
      return(wnc_nbr(va_arg(*ap, unsigned int), "0123456789abcdef"));
   else if (n == 'X')
      return(wnc_nbr(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
   return(0);
}

static int check_spec(const char n)
{
   char     *specs;
   int   i;

   specs = "cspdiuxX%";
   i = 0;
   while (specs[i] != '\0')
   {
      if(specs[i] == n)
            wnc_method(n);
      i++;
   }
   return(0);
}

int   printf(const char *format, ... )
{
   va_list  ap;
   size_t   i;
   int   count;

   va_start(ap, format);
   i = 0;
   while (format[i] != '\0')
   {
      count = 0;
      if (format[i] == '%')
      {
         check_spec(format[i + 1]);
         i++;
      }
      write(1, &format[i], 1);
      i++;
      count++;
   }
   va_end(ap);
   return(count);
}
