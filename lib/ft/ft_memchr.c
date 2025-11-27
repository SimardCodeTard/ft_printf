/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:25:27 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:27:21 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t	*cst_s;
	uint8_t	cst_c;
	size_t	i;

	cst_s = (uint8_t *) s;
	cst_c = (uint8_t) c;
	i = 0;
	while (i < n)
	{
		if (cst_s[i] == cst_c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
