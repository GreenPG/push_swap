/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:53:28 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/05 16:38:23 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	strtab_cat(char **dst, char **src, size_t dst_end)
{
	int		j;

	j = 0;
	while (src[j])
	{
		dst[dst_end + j] = ft_strdup(src[j]);
		j++;
	}
	dst[dst_end + j] = 0;
}

char	**join_strtab(char **stab1, char **stab2)
{
	char	**new_stab;
	size_t	stab1_len;
	size_t	stab2_len;
	int		i;

	if (stab2 == 0)
		return (NULL);
	stab1_len = strtab_len(stab1);
	stab2_len = strtab_len(stab2);
	new_stab = malloc(sizeof(char **) * (stab1_len + stab2_len + 1));
	if (!new_stab)
		return (0);
	i = 0;
	while (stab1[i])
	{
		new_stab[i] = ft_strdup(stab1[i]);
		i++;
	}
	strtab_cat(new_stab, stab2, i);
	free(stab1);
	return (new_stab);
}

size_t	strtab_len(char **strtab)
{
	int	len;

	if (!strtab)
		return (0);
	len = 0;
	while (strtab[len] != 0)
		len++;
	return (len);
}

size_t	get_lst_size(t_circ_list *lst)
{
	t_circ_list	*elem;
	size_t		size;

	elem = lst->next;
	size = 0;
	while (elem != lst)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

void	sort_chose(size_t lst_size, t_circ_list *a, t_circ_list *b)
{
	(void)b;
	if (lst_size <= 3)
		sort_3(a);
	else if (lst_size <= 5)
		sort_5(a, b);
}
