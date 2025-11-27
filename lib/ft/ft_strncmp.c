/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:43:15 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:29:18 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	uint8_t	*u_s1;
	uint8_t	*u_s2;

	u_s1 = (uint8_t *) s1;
	u_s2 = (uint8_t *) s2;
	i = 0;
	while ((u_s1[i] || u_s2[i]) && i < n)
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	if (i < n)
		return (u_s1[i] - u_s2[i]);
	return (0);
}
