/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:13:39 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/01 16:44:54 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_circ_list	*c_lst_new(void)
{
	t_circ_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (0);
	lst->prev = lst;
	lst->next = lst;
	return (lst);
}

void	c_lst_add_front(t_circ_list *lst, int content)
{
	t_circ_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
	{
		c_lst_clear(lst);
		return ;
	}
	new_elem->content = content;
	new_elem->prev = lst->prev;
	new_elem->next = lst;
	lst->prev->next = new_elem;
	lst->prev = new_elem;
}

void	c_lst_add_back(t_circ_list *lst, int content)
{
	t_circ_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
	{
		c_lst_clear(lst);
		return ;
	}
	new_elem->content = content;
	new_elem->prev = lst;
	new_elem->next = lst->next;
	lst->next->prev = new_elem;
	lst->next = new_elem;
}

void	c_lst_del(t_circ_list *elem)
{
	if (!elem)
		return ;
	free(elem);
}

void	c_lst_clear(t_circ_list *list)
{
	t_circ_list	*tmp;
	t_circ_list	*it;

	tmp = NULL;
	it = list->next;
	while (it != list)
	{
		tmp = it;
		c_lst_del(it);
		it = tmp->next;
	}
	free(list);
}
