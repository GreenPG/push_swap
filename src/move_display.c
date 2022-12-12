/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:17 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 17:16:01 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	display_move(t_move_list *lst)
{
	if (!lst)
		return ;
	lst = lst->next;
	while (lst)
	{
		if (!lst->next)
			ft_printf("%s\n", lst->move);
		else if (lst->move[0] == lst->next->move[0])
			lst = double_move(lst);
		else
			ft_printf("%s\n", lst->move);
		lst = lst->next;
	}
}

t_move_list	*double_move(t_move_list *lst)
{
	if (lst->move[0] == 's' && (lst->move[1] != lst->next->move[1]))
	{
		ft_printf("ss\n");
		lst = lst->next;
	}
	if (lst->move[0] == 'p' && (lst->move[1] != lst->next->move[1]))
	{
		ft_printf("pp\n");
		lst = lst->next;
	}
	if (lst->move[0] == 'r' && lst->move[1] == 'r' && (lst->move[2]
			!= lst->next->move[2]))
	{
		ft_printf("rrr\n");
		lst = lst->next;
	}
	else if (lst->move[1] != 'r' && lst->next->move[1] != 'r' && lst->move[1]
		!= lst->next->move[1])
	{	
		ft_printf("rr\n");
		lst = lst->next;
	}
	else
		ft_printf("%s\n", lst->move);
	return (lst);
}
