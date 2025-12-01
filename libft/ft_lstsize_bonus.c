/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:59:37 by smenard           #+#    #+#             */
/*   Updated: 2025/11/13 20:37:39 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	lst_has_cycle(t_list *lst)
{
	const t_list	*the_chosen_one = lst;

	if (!lst)
		return (false);
	while (lst->next)
	{
		lst = lst->next;
		if (lst == the_chosen_one)
			return (true);
	}
	return (false);
}

int	ft_lstsize(t_list *lst)
{
	t_list		*stop_value;
	uint16_t	size;

	if (!lst)
		return (0);
	stop_value = NULL;
	if (lst_has_cycle(lst))
		stop_value = lst;
	size = 0;
	while (lst->next != stop_value)
	{
		lst = lst->next;
		size++;
	}
	if (lst)
		size++;
	return (size);
}
