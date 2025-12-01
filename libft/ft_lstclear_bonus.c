/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:56:26 by smenard           #+#    #+#             */
/*   Updated: 2025/11/17 13:25:55 by smenard          ###   ########.fr       */
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

static void	ft_lstclear_cyclic(t_list **lst, void (*del)(void *),
				t_list *the_chosen_one)
{
	if (*lst == the_chosen_one)
		return ;
	ft_lstclear_cyclic(&(*lst)->next, del, the_chosen_one);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	if (lst_has_cycle(*lst))
		return (ft_lstclear_cyclic(lst, del, (*lst)->next));
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
