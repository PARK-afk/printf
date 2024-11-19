/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:24:05 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 06:29:33 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int num)
{
	int			num_len;
	long long	new_num;

	num_len = 0;
	new_num = (long long) num;
	if (new_num < 0)
	{
		write (1, "-", 1);
		new_num = -new_num;
		num_len++;
	}
	if (new_num >= 10)
	{
		num_len += ft_put_nbr(new_num / 10);
		num_len += ft_put_nbr(new_num % 10);
	}
	else
	{
		num_len += ft_print_char(new_num + '0');
	}
	return (num_len);
}

int	ft_print_nbr(int num)
{
	int					ptr_len;

	ptr_len = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		ptr_len++;
	}
	else
		ptr_len += ft_put_nbr(num);
	return (ptr_len);
}
