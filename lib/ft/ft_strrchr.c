/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:34:16 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 21:15:05 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = NULL;
	while (*s)
	{
		if (*s == (uint8_t) c)
			found = (char *) s;
		s++;
	}
	if (!((uint8_t) c))
		return ((char *) s);
	return (found);
}
