/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:28:54 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:32:02 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static int	ft_iswhitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	uint32_t	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += (nptr[i++] - 48);
	}
	return ((int)(res * sign));
}
