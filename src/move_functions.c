/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:31:48 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 14:13:18 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_circ_list *lst, t_move_list *move_list, char	*stack)
{
	lst->next->prev = lst->prev;
	lst->prev->next = lst->next;
	lst->next = lst->prev;
	lst->prev = lst->next->prev;
	lst->prev->next = lst;
	lst->next->prev = lst;
	if (stack[0] == 'a')
		mv_lst_addback(move_list, "rra");
	else
		mv_lst_addback(move_list, "rrb");
}

void	swap(t_circ_list *lst, t_move_list *move_list, char	*stack)
{
	t_circ_list	*first;
	t_circ_list	*second;

	first = lst->next;
	second = first->next;
	lst->next = second;
	second->prev = lst;
	first->prev = second;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	if (stack[0] == 'a')
		mv_lst_addback(move_list, "sa");
	else
		mv_lst_addback(move_list, "sb");
}

void	push(t_circ_list *src, t_circ_list *dst, t_move_list *move_list,
			char	*stack)
{
	t_circ_list	*elem_to_push;

	elem_to_push = src->next;
	src->next = elem_to_push->next;
	src->next->prev = src;
	elem_to_push->prev = dst;
	elem_to_push->next = dst->next;
	dst->next->prev = elem_to_push;
	dst->next = elem_to_push;
	if (stack[0] == 'a')
		mv_lst_addback(move_list, "pa");
	else
		mv_lst_addback(move_list, "pb");
}

void	rotate(t_circ_list *lst, t_move_list *move_list, char	*stack)
{
	lst->next->prev = lst->prev;
	lst->prev->next = lst->next;
	lst->prev = lst->next;
	lst->next = lst->prev->next;
	lst->prev->next = lst;
	lst->next->prev = lst;
	if (stack[0] == 'a')
		mv_lst_addback(move_list, "ra");
	else
		mv_lst_addback(move_list, "rb");
}
