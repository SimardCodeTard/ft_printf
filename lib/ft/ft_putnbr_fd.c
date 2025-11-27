/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:45:52 by smenard           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:41 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	ln;

	ln = (long) n;
	if (fd > -1)
	{
		if (ln < 0)
		{
			ln = -ln;
			write(fd, "-", 1);
		}
		if (ln > 9)
		{
			ft_putnbr_fd(ln / 10, fd);
			c = '0' + (ln % 10);
			write(fd, &c, 1);
			return ;
		}
		c = '0' + ln;
		write(fd, &c, 1);
	}
}
