/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:57:35 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 15:31:25 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		tmp = it->next;
		c_lst_del(it);
		it = tmp;
	}
	free(list);
}

void	mv_lst_del(t_move_list *elem)
{
	if (!elem)
		return ;
	free(elem);
}

void	mv_lst_clear(t_move_list *lst)
{
	t_move_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		mv_lst_del(lst);
		lst = tmp;
	}
	free(lst);
}

void	free_lists(t_lists *lists)
{
	if (lists->a)
		c_lst_clear(lists->a);
	if (lists->b)
		c_lst_clear(lists->b);
	if (lists->move_list)
		mv_lst_clear(lists->move_list);
	free(lists);
}
