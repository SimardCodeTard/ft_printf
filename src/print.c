/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:09:42 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 12:03:11 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

ssize_t	ft_putnbr_base_signed(int64_t num, t_string base)
{
	ssize_t			total_write_count;

	total_write_count = 0;
	if (num < 0)
	{
		total_write_count++;
		write(STDOUT_FILENO,"-", 1);
		num = -num;
	}
	return (ft_putnbr_base(num, base) + total_write_count);
}

ssize_t	ft_putstr(t_string str)
{
	size_t	len;

	if (str == NULL)
		return (write(STDOUT_FILENO,"(null)", 6));
	len = ft_strlen(str);
	return (write(STDOUT_FILENO,str, len));
}

ssize_t	ft_putnbr_base(uint64_t num, t_string base)
{
	const size_t	base_len = ft_strlen(base);
	ssize_t			write_result;
	ssize_t			total_write_count;
	char			c;

	write_result = 0;
	total_write_count = 0;
	if (num > 9)
	{
		write_result = ft_putnbr_base(num / base_len, base);
		if (write_result == -1)
			return (-1);
		total_write_count += write_result;
		c = base[num % base_len];
		write_result = write(STDOUT_FILENO,&c, 1);
		return (write_result + total_write_count);
	}
	c = base[num];
	write_result = write(STDOUT_FILENO,&c, 1);
	if (write_result == -1)
		return (-1);
	return (write_result + total_write_count);
}

ssize_t	ft_print_arg(t_arg arg)
{
	if (arg.value == NULL && (arg.type == PTR || arg.type == STRING))
	{
		if (arg.type == PTR)
			return (ft_putstr("(null)"));
		else
			return (ft_putstr("(nil)"));
	}
	else if (arg.type == CHAR || arg.type == PERCENT)
		return (write(STDOUT_FILENO,arg.value, 1));
	else if (arg.type == STRING)
		return (ft_putstr(*(t_string *) arg.value));
	else if (arg.type == INT)
		return (ft_putnbr_base_signed(*((int32_t *) arg.value),
				DECIMAL_CHARSET));
	else if (arg.type == UINT)
		return (ft_putnbr_base((uint32_t) *(int32_t *) arg.value,
				DECIMAL_CHARSET));
	else if (arg.type == LHEX)
		return (ft_putnbr_base(ft_abs(*(int32_t *) arg.value), LHEX_CHARSET));
	else if (arg.type == UHEX)
		return (ft_putnbr_base(ft_abs(*(int32_t *) arg.value), UHEX_CHARSET));
	else if (arg.type == PTR)
		return (ft_putnbr_base(*(uint64_t *) arg.value, DECIMAL_CHARSET));
	return (-1);
}

ssize_t	ft_print_substr(t_string str)
{
	return (write(STDOUT_FILENO,str, ft_strlen_until(str, '%')));
}
