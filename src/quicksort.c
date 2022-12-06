/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:29:34 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/06 15:49:18 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quicksort(t_circ_list *a, t_circ_list *b)
{
	int	pivot;
	t_circ_list *elem;

	pivot = a->next->content;
	elem = a->next;
	while (elem != a)
	{
		if (elem->content > pivot)
		{
			push(a, b);
			ft_printf("pa\n");
		}
		else
		{
			rotate(b);
			ft_printf("rb\n");
			push(a, b);
			ft_printf("pa\n");
		}
		elem = elem->next;
	}
}
