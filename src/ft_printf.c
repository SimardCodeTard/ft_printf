/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:53:40 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 11:50:23 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_printf(char *str, ...)
{
	const size_t	str_len = ft_strlen(str);
	va_list			ap;
	size_t			i;
	t_arg			arg;
	ssize_t			wrote_count;

	va_start(ap, str);
	wrote_count = 0;
	i = 0;
	while (i < str_len)
	{
		i += ft_print_substr(str + i);
		wrote_count += i;
		if (i < str_len)
		{
			arg = ft_parse_arg(str + i, ap, &i);
			wrote_count += ft_print_arg(arg);
			i++;
			free(arg.value);
		}
	}
	va_end(ap);
	return (wrote_count);
}
