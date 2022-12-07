/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:59:48 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/07 15:56:05 by gpasquet         ###   ########.fr       */
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
		while (input[i][j] == ' ')
			j++;
		if (input[i][j] == '-')
			j++;
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
	t_circ_list	*b;
	t_circ_list	*disp_lst_a;
	t_circ_list	*disp_lst_b;

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
	b = c_lst_new();
	put_index(a);
	disp_lst_a = a->next;
/*	ft_printf("-------------------------\nBefore sorting:\n");
	while (disp_lst_a != a)
	{
		ft_printf("%d\n", disp_lst_a->content);
		disp_lst_a = disp_lst_a->next;
	}
	ft_printf("\n------------------------\n");
*/	a->lst_size = get_lst_size(a);
	sort_chose(a->lst_size, a, b);
	disp_lst_a = a->next;
	disp_lst_b = b->next;
/*	ft_printf("-------------------------\nAfter sorting:\n");
	while (disp_lst_a != a)
	{
		ft_printf("%d	", disp_lst_a->content, disp_lst_b->content);
		if (disp_lst_b != b)
			ft_printf("%d\n", disp_lst_b->content);
		else
			write(1, "\n", 1);
		disp_lst_a = disp_lst_a->next;
		disp_lst_b = disp_lst_b->next;
	}*/
	return (0);
}
