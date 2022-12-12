/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:22:09 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 10:35:59 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rot_up_a(t_circ_list *elem, t_circ_list *a, t_move_list *move_list)
{
	while (elem->prev != a)
		rotate(a, move_list, "a");
}

void	rot_up_b(t_circ_list *elem, t_circ_list *b, t_move_list *move_list)
{
	while (elem->prev != b)
		rotate(b, move_list, "b");
}

void	rot_down_a(t_circ_list *elem, t_circ_list *a, t_move_list *move_list)
{
	while (elem->prev != a)
		reverse(a, move_list, "a");
}

void	rot_down_b(t_circ_list *elem, t_circ_list *b, t_move_list *move_list)
{
	while (elem->prev != b)
		reverse(b, move_list, "b");
}
