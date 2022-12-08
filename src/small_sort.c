/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:49 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/08 10:05:40 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_circ_list *a)
{
	if (a->next->content > a->next->next->content
		&& a->next->next->content > a->prev->content)
	{
		ft_printf("sa\n");
		swap(a);
		ft_printf("rra\n");
		reverse(a);
	}
	else if (a->next->content > a->prev->content
		&& a->next->next->content < a->prev->content)
	{	
		rotate(a);
		ft_printf("ra\n");
	}
	else
		sort_3_next(a);
}

void	sort_3_next(t_circ_list *a)
{
	if (a->next->content > a->next->next->content)
	{
		ft_printf("sa\n");
		swap(a);
	}
	else if (a->next->content < a->next->next->content
			&& a->next->next->content > a->prev->content)
	{
		reverse(a);
		ft_printf("rra\n");
		if (a->next->content > a->next->next->content)
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
}

void	sort_5(t_circ_list *a, t_circ_list *b)
{
	int	min;

	while (a->next != a && check_sorted(a) == 0 && get_lst_size(a) > 3)
	{
		min = get_min_value(a);
		sort_5_r_or_rr(a, min);
		push(a, b);
		ft_printf("pb\n");
	}
	sort_3(a);
	while (b->next != b)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}

void	sort_5_r_or_rr(t_circ_list *a, int min)
{
	while (a->next->content != min)
	{
		if (a->next->next->content == min)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			reverse(a);
			ft_printf("rra\n");
		}
	}
}
