/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:53:12 by junsepar          #+#    #+#             */
/*   Updated: 2023/01/17 06:17:42 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_print_nbr(int num);
int				ft_put_nbr(int num);
void			ft_printnbr_unsigned(int n);
int				ft_put_add(unsigned long long num);
int				ft_print_add(void *ptr);
int				ft_hex_len(unsigned int hex);
void			ft_put_hex(unsigned int hex_numi, char format);
int				ft_print_hex(unsigned int hex_num, char format);
void			ft_putstr(char *str);
int				ft_print_str(char *str);
char			*ft_trans_str(char *num_str, int num, int num_len);
int				ft_print_percent(void);
int				ft_numlen(int num);
int				ft_unsigned_num_len(unsigned int num);
int				ft_print_unsigned(unsigned int num);
int				ft_print_char(int c);
int				check_parse(va_list *arg_ptr, char format);
int				ft_printf(const char *format, ...);

#endif
