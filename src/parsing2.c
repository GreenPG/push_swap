/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:10:43 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 14:11:19 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_almost_sorted(t_circ_list *a)
{
	t_circ_list	*tmp;
	int			max_index;
	int			min_index;

	max_index = get_max_index(a);
	min_index = get_min_index(a);
	tmp = a->next->next;
	while (tmp != a)
	{
		if (tmp->content < tmp->prev->content && (tmp->index
				!= min_index || tmp->prev->index != max_index))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_duplicate(t_circ_list *lst)
{
	t_circ_list	*tmp;
	t_circ_list	*reverse;

	tmp = lst->next;
	while (tmp != lst)
	{
		reverse = tmp->prev;
		while (reverse != lst)
		{
			if (reverse->content == tmp->content)
				return (-1);
			reverse = reverse->prev;
		}
		tmp = tmp->next;
	}
	return (0);
}
