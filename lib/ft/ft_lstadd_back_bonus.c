/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:39:02 by smenard           #+#    #+#             */
/*   Updated: 2025/11/14 10:10:47 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev_last;

	if (!lst)
		return ;
	prev_last = ft_lstlast(*lst);
	if (!prev_last)
		*lst = new;
	else
		prev_last->next = new;
}
