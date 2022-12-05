/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:49 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/05 17:15:05 by gpasquet         ###   ########.fr       */
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
	if (a->next->content > a->next->next->content
		&& a->next->next->content < a->prev->content)
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
	while (check_sorted(a) == 0 || b->next != b)
	{
		if (a->next->content > a->next->next->content)
		{
			swap(a);
			ft_printf("sa\n");
		}
		else if (a->next->content > a->prev->content)
		{
			reverse(a);
			ft_printf("rra\n");
		}
		else
		{
			push(a, b);
			ft_printf("pa\n");
			push(a, b);
			ft_printf("pa\n");
			sort_3(a);
			while (b->next != b)
			{
				if (a->next->content > b->next->content)
				{
					push(b, a);
					ft_printf("pb\n");
				}
				else
				{
					rotate(a);
					ft_printf("ra\n");
				}
			}
		}
	}
}
