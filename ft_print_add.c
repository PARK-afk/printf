/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:34:51 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 03:32:47 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_add(unsigned long long num)
{
	int		num_len;

	num_len = 0;
	if (num >= 16)
	{
		num_len += ft_put_add(num / 16);
		num_len += ft_put_add(num % 16);
	}
	else
	{
		if (num <= 9)
			num_len += ft_print_char(num + '0');
		else
			num_len += ft_print_char((num - 10) + 'a');
	}
	return (num_len);
}

int	ft_print_add(void *ptr)
{
	int					ptr_len;
	unsigned long long	ptr_ull;

	ptr_len = 2;
	ptr_ull = (unsigned long long) ptr;
	write (1, "0x", 2);
	if (ptr_ull == 0)
	{
		write (1, "0", 1);
		ptr_len++;
	}
	else
		ptr_len += ft_put_add(ptr_ull);
	return (ptr_len);
}
