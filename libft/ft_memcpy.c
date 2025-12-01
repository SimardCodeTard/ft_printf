/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/13 17:26:21 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	uint8_t	*cst_dest;
	uint8_t	*cst_src;
	size_t	i;

	cst_dest = (uint8_t *) dest;
	cst_src = (uint8_t *) src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		(*(cst_dest + i)) = *(cst_src + i);
		i++;
	}
	return (dest);
}
