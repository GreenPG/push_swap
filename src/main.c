/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:59:48 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/12 17:36:43 by gpasquet         ###   ########.fr       */
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
		if (input[i][j] == '-' || input[i][j] == '+')
			j++;
		if (ft_isdigit(input[i][j]) != 1)
			return (-1);
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

t_lists	*initiate_lists(char **input)
{
	t_lists	*lists;

	lists = malloc(sizeof(*lists));
	lists->a = parsing(input);
	if (!lists->a)
	{
		ft_printf("Error\n");
		free(lists);
		exit(0);
	}
	if (check_sorted(lists->a) == 1)
	{
		free(lists);
		return (0);
	}
	lists->b = c_lst_new();
	lists->move_list = mv_lstnew("");
	put_index(lists->a);
	lists->a->lst_size = get_lst_size(lists->a);
	return (lists);
}

int	main(int ac, char **av)
{
	t_lists	*lists;

	if (ac == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	lists = initiate_lists(av + 1);
	sort_chose(lists);
	display_move(lists->move_list);
	free_lists(lists);
	return (0);
}
