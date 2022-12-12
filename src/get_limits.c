/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:02:37 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 14:03:44 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min_value(t_circ_list *a)
{
	t_circ_list	*elem;
	int			min;

	elem = a->next;
	min = elem->content;
	while (elem->next != a)
	{
		if (elem->next->content < min && elem != a)
			min = elem->next->content;
		elem = elem->next;
	}
	return (min);
}

int	get_max_value(t_circ_list *a)
{
	t_circ_list	*elem;
	int			max;

	elem = a->next;
	max = elem->content;
	while (elem->next != a)
	{
		if (elem->next->content > max)
			max = elem->next->content;
		elem = elem->next;
	}
	return (max);
}
