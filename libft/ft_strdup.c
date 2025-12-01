/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:43:01 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:32:26 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		s_len;
	char		*ns;
	uint32_t	i;

	i = 0;
	s_len = ft_strlen(s);
	ns = ft_calloc((s_len + 1), sizeof(char));
	if (!ns)
		return (NULL);
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	return (ns);
}
