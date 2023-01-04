/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:14:38 by mayoub            #+#    #+#             */
/*   Updated: 2022/10/19 15:29:11 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int	g_written_character = 0;

void	ft_puthexa(unsigned int decimal)
{
	char	str[16] = "0123456789abcdef";

	if (decimal > 16)
		ft_puthexa(decimal / 16);
	write(1, &str[decimal % 16], 1);
	g_written_character++;
}
int	ft_putnbr(long decimal)
{
	char	str[10] = "0123456789";

	if (decimal == INT_MAX)
	{
		write(1, "2147483647", 10);
		g_written_character = 10;
		return(0);
	}
	else if (decimal == INT_MIN)
	{
		write(1, "-2147483647", 11);
		g_written_character = 11;
		return (0);
	}
	else if (decimal > 10)
		ft_putnbr(decimal / 10);
	write(1, &str[decimal % 10], 1);
	g_written_character++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;

	g_written_character = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int		lengh = 0;
				char	*str = va_arg(arg, char *);
				if (!str)
					str = "(null)";
				while (str[lengh])
					lengh++;
				g_written_character = lengh;
				write(1, str, lengh);
			}
			else if (*format == 'd')
			{
				long long	decimal = va_arg(arg, int);
				if (decimal < 0)
				{
					write(1, "-", 1);
					decimal *= -1;
					g_written_character++;
				}
				if (ft_putnbr(decimal))
				{
					va_end(arg);
					return (g_written_character);
				}
			}
			else if (*format == 'x')
			{
				int	hexa = va_arg(arg, int);
				ft_puthexa(hexa);
			}
			format++;
		}
		else
			g_written_character += write(1, format++, 1);
	}
	va_end(arg);
	return (g_written_character);
}

int	main()
{
	int	age = -2;

	printf("%d\n", ft_printf("coucou\n"));
	ft_printf("54478\n");
	ft_printf("mon nom = %s\n", "Ayoub");
	printf("char=%d\n", ft_printf("mon age = %d\n", age));
	ft_printf("ceci est de l'hexadecimal = %x\n", age);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
}

