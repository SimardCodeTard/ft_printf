/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:19 by smenard           #+#    #+#             */
/*   Updated: 2025/11/14 10:08:05 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			((uint8_t *) dest)[i - 1] = ((uint8_t *) src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((uint8_t *) dest)[i] = ((uint8_t *) src)[i];
			i++;
		}
	}
	return (dest);
}
