/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:01:49 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:26:04 by smenard          ###   ########.fr       */
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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*stop_value;

	if (!lst || !f)
		return ;
	stop_value = NULL;
	if (lst_has_cycle(lst))
		stop_value = lst;
	while (lst->next != stop_value)
	{
		f(lst->content);
		lst = lst->next;
	}
	if (lst)
		f(lst->content);
}
