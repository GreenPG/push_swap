/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:09:33 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/01 16:32:54 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_circ_list	*parsing(char **input)
{
	t_circ_list	*a;
	int			i;
	char		**splitted_input;

	splitted_input = split_input(input);
	if (check_param_size(splitted_input) == -1 || check_digit(splitted_input)
		== -1)
		return (NULL);
	a = c_lst_new();
	if (!a)
		return (0);
	i = 0;
	while (splitted_input[i])
	{
		c_lst_add_front(a, ft_atoi(splitted_input[i]));
		i++;
	}
	if (check_duplicate(a) == -1)
	{	
		c_lst_clear(a);
		return (NULL);
	}
	return (a);
}

char	**split_input(char **input)
{
	char	**splitted_input;
	char	**splitted_arg;
	int		i;

	splitted_input = ft_calloc(sizeof(char *), 1);
	if (!splitted_input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		splitted_arg = ft_split(input[i], ' ');
		splitted_input = join_strtab(splitted_input, splitted_arg);
		free(splitted_arg);
		i++;
	}
	return (splitted_input);
}

int	check_param_size(char **input)
{
	int				i;
	int				j;
	long long int	tmp;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j] == '0')
			j++;
		input[i] += j;
		if (ft_strlen(input[i]) > 11)
			return (-1);
		tmp = ft_atoll(input[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

int	check_sorted(t_circ_list *a)
{
	t_circ_list	*tmp;

	tmp = a->next->next;
	while (tmp != a)
	{
		if (tmp->content < tmp->prev->content)
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
