/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:04 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/09 16:55:42 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_index(t_circ_list *a)
{
	int			min;
	size_t		index;
	size_t		lst_size;
	t_circ_list	*elem;

	lst_size = get_lst_size(a);
	min = get_min_value(a);
	index = 1;
	while (index <= lst_size)
	{
		elem = a->next;
		while (elem != a)
		{
			if (elem->content == min)
			{
				elem->index = index;
				index++;
				break ;
			}
			elem = elem->next;
		}
		min++;
	}
}

int	get_min_value(t_circ_list *a)
{
	t_circ_list	*elem;
	int			min;

	elem = a->next;
	min = elem->content;
	while (elem->next != a)
	{
		if (elem->next->content < min)
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

int	get_max_index(t_circ_list *a)
{
	int			max;
	t_circ_list	*elem;

	max = get_max_value(a);
	elem = a->next;
	while (elem->next != a)
	{
		if (elem->content == max)
			return (elem->index);
		elem = elem->next;
	}
	return (0);
}

int	get_min_index(t_circ_list *a)
{
	int			min;
	t_circ_list	*elem;

	min = get_min_value(a);
	elem = a->next;
	while (elem->next != a)
	{
		if (elem->content == min)
			return (elem->index);
		elem = elem->next;
	}
	return (0);
}
