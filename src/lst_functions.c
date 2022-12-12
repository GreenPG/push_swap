/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:13:39 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 17:15:59 by gpasquet         ###   ########.fr       */
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

t_move_list	*mv_lstnew(char	*str)
{
	t_move_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (0);
	lst->move = str;
	lst->next = NULL;
	return (lst);
}

void	mv_lst_addback(t_move_list *lst, char *move)
{
	t_move_list	*new_elem;
	t_move_list	*tmp;

	tmp = lst;
	new_elem = mv_lstnew(move);
	if (!new_elem)
	{
		mv_lst_clear(lst);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_elem;
}
