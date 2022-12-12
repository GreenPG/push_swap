/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:13:42 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 17:14:37 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_circ_list	*get_hold_first(t_circ_list *a, int max_chunk)
{
	t_circ_list	*elem;

	elem = a->next;
	while (elem != a)
	{
		if (elem->index <= max_chunk)
			return (elem);
		elem = elem->next;
	}
	return (0);
}

t_circ_list	*get_hold_second(t_circ_list *a, int max_chunk)
{
	t_circ_list	*elem;

	elem = a->prev;
	while (elem != a)
	{
		if (elem->index <= max_chunk)
			return (elem);
		elem = elem->prev;
	}
	return (0);
}

void	get_min_to_top(t_circ_list *lst, char lst_name,
		t_move_list *move_list)
{
	int			min;
	t_circ_list	*elem;

	min = get_min_value(lst);
	elem = lst->next;
	while (elem->content != min)
		elem = elem->next;
	if (nb_to_top(elem, lst) < nb_to_bottom(elem, lst))
	{
		if (lst_name == 'a')
			rot_up_a(elem, lst, move_list);
		else
			rot_up_b(elem, lst, move_list);
	}
	else
	{
		if (lst_name == 'a')
			rot_down_a(elem, lst, move_list);
		else
			rot_down_b(elem, lst, move_list);
	}
}

void	get_max_to_top(t_circ_list *lst, char lst_name, t_move_list *move_list)
{
	int			max;
	t_circ_list	*elem;

	max = get_max_value(lst);
	elem = lst->next;
	while (elem->content != max)
		elem = elem->next;
	if (nb_to_top(elem, lst) < nb_to_bottom(elem, lst))
	{	
		if (lst_name == 'a')
			rot_up_a(elem, lst, move_list);
		else
			rot_up_b(elem, lst, move_list);
	}
	else
	{
		if (lst_name == 'a')
			rot_down_a(elem, lst, move_list);
		else
			rot_down_b(elem, lst, move_list);
	}
}
