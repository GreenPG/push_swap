/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:18:40 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/13 17:17:10 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_last_chunk(t_lists *lists)
{
	t_circ_list	*elem;

	if (get_lst_size(lists->a) <= 3)
		sort_3(lists);
	else if (get_lst_size(lists->a) <= 5)
		sort_5(lists);
	else
	{
		elem = lists->a->next->next;
		while (check_sorted(lists->a) == 0)
		{
			if (elem->content < elem->prev->content)
			{
				swap(lists->a, lists->move_list, "a");
				elem = lists->a->next->next;
			}
			else
				elem = elem->next;
			rotate(lists->a, lists->move_list, "a");
		}
	}
}
