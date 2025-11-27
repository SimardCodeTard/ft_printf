/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:42 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:27:54 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t	*cst_s1;
	uint8_t	*cst_s2;
	size_t	i;

	cst_s1 = (uint8_t *) s1;
	cst_s2 = (uint8_t *) s2;
	i = 0;
	while (i < n)
	{
		if (cst_s1[i] != cst_s2[i])
			return (cst_s1[i] - cst_s2[i]);
		i++;
	}
	return (0);
}
