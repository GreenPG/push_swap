/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:49 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:31 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_chose(t_lists *lists)
{
	if (lists->a->lst_size <= 3)
		sort_3(lists);
	else if (lists->a->lst_size <= 5)
		sort_5(lists);
	else if (lists->a->lst_size <= 100)
		big_sort(lists, 5);
	else
		big_sort(lists, 10);
}

void	sort_3(t_lists *lists)
{
	if (lists->a->next->content > lists->a->next->next->content
		&& lists->a->next->next->content > lists->a->prev->content)
	{
		swap(lists->a, lists->move_list, "a");
		reverse(lists->a, lists->move_list, "a");
	}
	else if (lists->a->next->content > lists->a->prev->content
		&& lists->a->next->next->content < lists->a->prev->content)
		rotate(lists->a, lists->move_list, "a");
	else
		sort_3_next(lists->a, lists->move_list);
}

void	sort_3_next(t_circ_list *a, t_move_list *move_list)
{
	if (a->next->content > a->next->next->content)
		swap(a, move_list, "a");
	else if (a->next->content < a->next->next->content
		&& a->next->next->content > a->prev->content)
	{
		reverse(a, move_list, "a");
		if (a->next->content > a->next->next->content)
			swap(a, move_list, "a");
	}
}

void	sort_5(t_lists *lists)
{
	int	min;

	while (lists->a->next != lists->a && check_sorted(lists->a) == 0
		&& get_lst_size(lists->a) > 3)
	{
		min = get_min_value(lists->a);
		sort_5_r_or_rr(lists, min);
		push(lists->a, lists->b, lists->move_list, "b");
	}
	sort_3(lists);
	while (lists->b->next != lists->b)
		push(lists->b, lists->a, lists->move_list, "a");
}

void	sort_5_r_or_rr(t_lists *lists, int min)
{
	while (lists->a->next->content != min)
	{
		if (lists->a->next->next->content == min)
			rotate(lists->a, lists->move_list, "a");
		else
			reverse(lists->a, lists->move_list, "a");
	}
}
