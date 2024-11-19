/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:34:56 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 06:27:46 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_unsigned_num_len(unsigned int num)
{
	int	num_len;

	num_len = 0;
	while (num)
	{
		num /= 10;
		num_len++;
	}
	return (num_len);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n > UINT32_MAX)
		return ;
	if (n <= 9)
	{
		c = n + '0';
		write (1, &c, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
}

int	ft_print_unsigned(unsigned int num)
{
	int	num_len;

	num_len = ft_unsigned_num_len(num);
	if (num == 0)
	{
		write (1, "0", 1);
		num_len++;
	}
	else
		ft_putnbr_unsigned(num);
	return (num_len);
}
