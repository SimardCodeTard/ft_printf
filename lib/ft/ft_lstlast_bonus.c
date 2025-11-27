/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:31:35 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:26:54 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	lst_has_cycle(t_list *lst)
{
	t_list	*the_chosen_one;

	the_chosen_one = lst;
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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst_has_cycle(lst) || !lst)
		return (NULL);
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
