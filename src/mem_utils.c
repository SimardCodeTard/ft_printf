/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:22:10 by smenard           #+#    #+#             */
/*   Updated: 2025/12/15 12:42:00 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	*ft_memset(void *s, int c, size_t n)
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (!nmemb || !size)
		return (malloc(1));
	if (size > INT_MAX / nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_memset(s, 0, nmemb * size);
	return (s);
}
