/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:02:01 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 21:08:42 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	uint8_t	*cst_s;

	i = 0;
	cst_s = (uint8_t *) s;
	while (i < n)
	{
		*(cst_s + i) = c;
		i++;
	}
	return (s);
}
