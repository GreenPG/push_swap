/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:30:12 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/07 14:42:25 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_circ_list {
	int					content;
	int					index;
	int					lst_size;
	struct s_circ_list	*prev;
	struct s_circ_list	*next;
}	t_circ_list;

void		swap(t_circ_list *list);
void		push(t_circ_list *src, t_circ_list *dst);
void		rotate(t_circ_list *list);
void		reverse(t_circ_list *list);

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
size_t		get_lst_size(t_circ_list *lst);
void		sort_chose(size_t lst_size, t_circ_list *a, t_circ_list *b);

//	small_sort.c
void		sort_3(t_circ_list *a);
void		sort_3_next(t_circ_list *a);
void		sort_5(t_circ_list *a, t_circ_list *b);
void		sort_5_r_or_rr(t_circ_list *a, int min);

//	index_functions.c
void		put_index(t_circ_list *a);
int			get_min_value(t_circ_list *a);

//	big_sort.c
void		big_sort(t_circ_list *a, t_circ_list *b);

#endif
