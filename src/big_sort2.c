/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:29:33 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/08 17:36:25 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort2(t_circ_list *a, t_circ_list *b, int chunk_nb)
{
	t_circ_list	*elem;
	int			max_chunk;

	max_chunk = a->lst_size / chunk_nb;
	while (a->next != a)
	{
		elem = put_elem_top(a, max_chunk);
		if (!elem)
		{
			max_chunk += a->lst_size / chunk_nb;
			elem = put_elem_top(a, max_chunk);
		}
		if (b->next == b || b->next->content == get_min_value(b))
		{
			push(a, b);
			ft_printf("pb\n");
		}
		else
		{
			get_min_to_top(b, 'b');
			push(a, b);
			ft_printf("pb\n");
		}
	}
	while (b->next != b)
	{
		get_max_to_top(b, 'b');
		push(b, a);
		ft_printf("pa\n");

	}
}

t_circ_list	*put_elem_top(t_circ_list *a, int max_chunk)
{
	t_circ_list	*hold_first;
	t_circ_list	*hold_second;

	hold_first = get_hold_first(a, max_chunk);
	hold_second = get_hold_second(a, max_chunk);
	if (!hold_first && !hold_second)
		return (0);
	if (nb_to_top(hold_first, a) < nb_to_bottom(hold_second, a))
	{
		rot_up_a(hold_first, a);
		return (hold_first);
	}	
	else
	{
		rot_down_a(hold_second, a);
		return (hold_second);
	}
}

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

int			nb_to_top(t_circ_list *elem, t_circ_list *lst)
{
	int	rr_count;

	rr_count = 0;
	while (elem->prev != lst)
	{
		elem = elem->prev;
		rr_count++;
	}
	return (rr_count);
}

int			nb_to_bottom(t_circ_list *elem, t_circ_list *lst)
{
	int	r_count;

	r_count = 0;
	while (elem->prev != lst)
	{
		elem = elem->next;
		r_count++;
	}
	return (r_count);
}

void		get_min_to_top(t_circ_list *lst, char lst_name)
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
			rot_up_a(elem, lst);
		else
			rot_up_b(elem, lst);
	}
	else
	{
		if (lst_name == 'a')
			rot_down_a(elem, lst);
		else
			rot_down_b(elem, lst);
	}
}

void		get_max_to_top(t_circ_list *lst, char lst_name)
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
			rot_up_a(elem, lst);
		else
			rot_up_b(elem, lst);
	}
	else
	{
		if (lst_name == 'a')
			rot_down_a(elem, lst);
		else
			rot_down_b(elem, lst);
	}
}
