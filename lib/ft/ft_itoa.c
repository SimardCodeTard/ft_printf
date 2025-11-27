/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:18:00 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 20:55:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	ft_abs(int32_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int8_t	numlen(uint32_t n)
{
	int8_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	int8_t		len;
	int8_t		i;
	uint32_t	u_n;
	bool		is_neg;

	is_neg = n < 0;
	len = numlen(ft_abs((int32_t) n));
	if (is_neg)
		len++;
	i = 0;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	u_n = ft_abs(n);
	while (i < len)
	{
		res[len - i - 1] = (u_n % 10) + '0';
		u_n /= 10;
		i++;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
