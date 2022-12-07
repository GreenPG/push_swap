/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:22:09 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/07 13:40:58 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort(t_circ_list *a, t_circ_list *b)
{
	int			pivot;
	t_circ_list	*elem;

	elem = a->next;
	pivot = a->lst_size / 2;
	while (elem != a)
	{
		if (elem->index >= pivot)
		{
			push(a, b);
			ft_printf("pa\n");
		}
		else
		{
			push(a, b);
			ft_printf("pa\n");
			rotate(b);
			ft_printf("ra\n");
		}
	}
}
