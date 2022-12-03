/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:59:48 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:15 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digit(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_circ_list	*a;
//	t_circ_list	*b;
	t_circ_list	*disp_lst;

	if (ac == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	a = parsing(av + 1);
	if (!a)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_sorted(a) == 1)
		return (0);
	disp_lst = a->next;
	while (disp_lst != a)
	{
		ft_printf("%d\n", disp_lst->content);
		disp_lst = disp_lst->next;
	}
	return (0);
}
