/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:53:40 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 17:15:28 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static ssize_t	handle_arg(t_string str, va_list ap, size_t *ptr_i)
{
	t_arg	arg;
	size_t	wrote_count;

	arg = ft_parse_arg(str, ap, ptr_i);
	wrote_count = ft_print_arg(arg);
	free(arg.value);
	return (wrote_count);
}

int	ft_printf(char *str, ...)
{
	const size_t	str_len = ft_strlen(str);
	va_list			ap;
	size_t			i;
	ssize_t			wrote_count;
	ssize_t			last_write_count;

	va_start(ap, str);
	wrote_count = 0;
	i = 0;
	while (i < str_len)
	{
		last_write_count = write(STDOUT_FILENO, str + i,
				ft_strlen_until(str + i, '%'));
		i += last_write_count;
		wrote_count += last_write_count;
		if (i < str_len)
		{
			last_write_count = handle_arg(str + i, ap, &i);
			wrote_count += last_write_count;
			i++;
		}
	}
	va_end(ap);
	return (wrote_count);
}
