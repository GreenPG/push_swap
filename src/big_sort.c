/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:22:09 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/08 16:40:10 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rot_up_a(t_circ_list *elem, t_circ_list *a)
{
	while (elem->prev != a)
	{
		reverse(a);
		ft_printf("rra\n");
	}
}

void	rot_up_b(t_circ_list *elem, t_circ_list *b)
{
	while (elem->prev != b)
	{
		reverse(b);
		ft_printf("rrb\n");
	}
}

void	rot_down_a(t_circ_list *elem, t_circ_list *a)
{
	while (elem->prev != a)
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

void	rot_down_b(t_circ_list *elem, t_circ_list *b)
{
	while (elem->prev != b)
	{
		rotate(b);
		ft_printf("rb\n");
	}
}
