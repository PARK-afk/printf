/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:34:58 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 01:07:53 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int hex)
{
	int	hl;

	hl = 0;
	while (hex)
	{
		hl++;
		hex /= 16;
	}
	return (hl);
}

void	ft_put_hex(unsigned int hex_num, char format)
{
	if (hex_num >= 16)
	{
		ft_put_hex(hex_num / 16, format);
		ft_put_hex(hex_num % 16, format);
	}
	else
	{
		if (hex_num <= 9)
			ft_print_char(hex_num + '0');
		else
		{
			if (format == 'x')
				ft_print_char(hex_num - 10 + 'a');
			else if (format == 'X')
				ft_print_char(hex_num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int hex_num, char format)
{
	int	hex_len;

	hex_len = ft_hex_len(hex_num);
	if (hex_num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(hex_num, format);
	return (hex_len);
}
