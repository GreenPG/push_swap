/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:30:12 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/01 16:39:56 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_circ_list {
	int					content;
	struct s_circ_list	*prev;
	struct s_circ_list	*next;
}	t_circ_list;

void		swap(t_list *list);
void		push(t_list *src, t_list *dst);
void		rotate(t_list *list);
void		r_rotate(t_list *list);
//	main.c
int			check_digit(char **input);
//	lst_functions.c
t_circ_list	*c_lst_new(void);
void		c_lst_add_front(t_circ_list *lst, int content);
void		c_lst_add_back(t_circ_list *lst, int content);
void		c_lst_del(t_circ_list *elem);
void		c_lst_clear(t_circ_list *lst);
//	parsing.c
int			check_param_size(char **input);
t_circ_list	*parsing(char **input);
int			check_sorted(t_circ_list *a);
int			check_duplicate(t_circ_list *lst);
char		**split_input(char **input);

//	utils.c
size_t		strtab_len(char **strtab);
char		**join_strtab(char **stab1, char **stab2);
void		strtab_cat(char **dst, char **src, size_t dst_end);

#endif
