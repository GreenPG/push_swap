/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:29:33 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/13 16:32:30 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort(t_lists *lists, int chunk_nb)
{
	int			max_chunk;
	int			pivot;

	max_chunk = lists->a->lst_size / chunk_nb;
	pivot = max_chunk / 2;
	partitioning(lists, max_chunk, pivot);
	sort_last_chunk(lists);
	while (lists->b->next != lists->b)
	{
		get_max_to_top(lists->b, 'b', lists->move_list);
		push(lists->b, lists->a, lists->move_list, "a");
		if (lists->a->next->content > lists->a->next->next->content
			&& lists->a->next != lists->a->prev)
			swap(lists->a, lists->move_list, "a");
	}
}

void	partitioning(t_lists *lists, int max_chunk, int pivot)
{
	t_circ_list	*elem;
	int			increment;

	increment = max_chunk;
	while (max_chunk < lists->a->lst_size)
	{
		elem = put_elem_top(lists->a, max_chunk, lists->move_list);
		if (!elem)
		{
			max_chunk += increment;
			pivot += increment;
			elem = put_elem_top(lists->a, max_chunk, lists->move_list);
		}
		if (elem->index <= pivot || lists->b->next == lists->b)
			push(lists->a, lists->b, lists->move_list, "b");
		else
		{
			push(lists->a, lists->b, lists->move_list, "b");
			rotate(lists->b, lists->move_list, "b");
		}
	}
}

t_circ_list	*put_elem_top(t_circ_list *a, int max_chunk, t_move_list *move_list)
{
	t_circ_list	*hold_first;
	t_circ_list	*hold_second;

	hold_first = get_hold_first(a, max_chunk);
	hold_second = get_hold_second(a, max_chunk);
	if (!hold_first && !hold_second)
		return (0);
	if (nb_to_top(hold_first, a) < nb_to_bottom(hold_second, a))
	{
		rot_up_a(hold_first, a, move_list);
		return (hold_first);
	}	
	else
	{
		rot_down_a(hold_second, a, move_list);
		return (hold_second);
	}
}

int	nb_to_top(t_circ_list *elem, t_circ_list *lst)
{
	int	rr_count;

	rr_count = 0;
	while (elem->prev != lst)
	{
		elem = elem->prev;
		rr_count++;
	}
	return (rr_count);
}

int	nb_to_bottom(t_circ_list *elem, t_circ_list *lst)
{
	int	r_count;

	r_count = 0;
	while (elem->prev != lst)
	{
		elem = elem->next;
		r_count++;
	}
	return (r_count);
}
