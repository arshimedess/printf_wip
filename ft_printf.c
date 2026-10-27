/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/26 12:38:18 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/27 18:14:30 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int wnc_method(const char n)
{
   if (n == 'c')
      wnc_char(c, 1);
   else if (n == 's')
      wnc_str(c, 1);
   else if (n == 'p')
      do this ;
   else if (n == 'd' || n == 'i')
      do this ;
   else if (n == 'u')
      do this ;
   else if (n == 'x')
      do this ;
   else if (n == 'X')
      do this ;
   else if (n == '%')
      do this ;
}

int check_spec(const char n)
{
   char     *specs;
   size_t   i;

   specs = "cspdiuxX%";
   i = 0;
   while (specs[i] != '\0')
   {
      if(specs[i] == n)
         {
            wnc_method(n);
         }
      i++;
   }
   return(i);
}

int   printf(const char *format, ... )
{
   va_list  ap;
   size_t   i;
   size_t   count;

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

/* printf example */
#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65+32);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}