/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:44:40 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 00:29:21 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	check_parse(va_list *arg_ptr, char format)
{
	int	prt_len;

	prt_len = 0;
	if (format == 'c')
		prt_len += ft_print_char(va_arg(*arg_ptr, int));
	else if (format == 's')
		prt_len += ft_print_str(va_arg(*arg_ptr, char *));
	else if (format == 'p')
		prt_len += ft_print_add(va_arg(*arg_ptr, void *));
	else if (format == 'd' || format == 'i')
		prt_len += ft_print_nbr(va_arg(*arg_ptr, int));
	else if (format == 'u')
		prt_len += ft_print_unsigned(va_arg(*arg_ptr, unsigned int));
	else if (format == 'x' || format == 'X')
		prt_len += ft_print_hex(va_arg(*arg_ptr, unsigned int), format);
	else if (format == '%')
		prt_len += ft_print_percent();
	return (prt_len);
}

int	ft_printf(const char *format, ...)
{
	int		va_len;
	va_list	arg_ptr;

	va_len = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			va_len += check_parse(&arg_ptr, *format);
		}
		else
		{
			ft_print_char(*format);
			va_len++;
		}
		format++;
	}
	va_end(arg_ptr);
	return (va_len);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_printf("%s  ab", "ac"));
}*/
