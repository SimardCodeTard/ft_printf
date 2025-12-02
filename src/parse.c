/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:09:49 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 11:50:13 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static size_t	ft_parse_flags(t_arg *arg, t_string str)
{
	size_t	j;

	j = 0;
	(void) arg;
	while (ft_strchr(FLAGS, str[j]))
		j++;
	return (j);
}

static t_arg	set_32bits_value(t_arg arg, va_list ap)
{
	arg.value = malloc(sizeof(int32_t));
	if (!arg.value)
		return (arg);
	*(int32_t *) arg.value = va_arg(ap, int32_t);
	return (arg);
}

static t_arg	set_64bits_value(t_arg arg, va_list ap)
{
	arg.value = malloc(sizeof(int64_t));
	if (!arg.value)
		return (arg);
	*(int64_t *) arg.value = va_arg(ap, int64_t);
	return (arg);
}

t_arg	ft_parse_arg(t_string str, va_list ap, size_t *i)
{
	t_arg		arg;
	size_t		j;

	j = ft_parse_flags(&arg, str);
	arg.type = str[++j];
	*i += j;
	if (arg.type == CHAR || arg.type == INT || arg.type == UINT
		|| arg.type == LHEX || arg.type == UHEX)
		arg = set_32bits_value(arg, ap);
	else if (arg.type == PTR || arg.type == STRING)
		arg = set_64bits_value(arg, ap);
	else if (arg.type == PERCENT)
		arg.value = ft_strdup("%");
	else
	{
		arg.type = INVALID;
		arg.value = NULL;
	}
	return (arg);
}
