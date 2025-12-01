/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:46:09 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:16:49 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s_joined;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	s_joined = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!s_joined)
		return (NULL);
	if (s1)
		ft_memcpy(s_joined, s1, s1_len);
	if (s2)
		ft_memcpy(s_joined + s1_len, s2, s2_len);
	return (s_joined);
}
