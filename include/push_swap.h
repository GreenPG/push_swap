/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:30:12 by gpasquet          #+#    #+#             */
/*   Updated: 2022/12/13 17:04:31 by gpasquet         ###   ########.fr       */
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

typedef struct s_move_list {
	char				*move;
	struct s_move_list	*next;
}	t_move_list;

typedef struct s_lists {
	t_circ_list			*a;	
	t_circ_list			*b;	
	t_move_list			*move_list;
}	t_lists;

//	move_functions.c
void		swap(t_circ_list *list, t_move_list *move_list, char	*stack);
void		push(t_circ_list *src, t_circ_list *dst, t_move_list *move_list,
				char	*stack);
void		rotate(t_circ_list *list, t_move_list *move_list, char	*stack);
void		reverse(t_circ_list *list, t_move_list *move_list, char	*stack);

//	main.c
int			check_digit(char **input);
t_lists		*initiate_lists(char **input);

//	lst_functions.c
t_circ_list	*c_lst_new(void);
void		c_lst_add_front(t_circ_list *lst, int content);
void		c_lst_add_back(t_circ_list *lst, int content);
t_move_list	*mv_lstnew(char *str);
void		mv_lst_addback(t_move_list *lst, char *move);
void		display_move(t_move_list *lst);
t_move_list	*double_move(t_move_list *lst);

//	free_functions.c
void		c_lst_del(t_circ_list *elem);
void		c_lst_clear(t_circ_list *lst);
void		mv_lst_del(t_move_list *elem);
void		mv_lst_clear(t_move_list *lst);
void		free_lists(t_lists *lists);

//	parsing.c
int			check_param_size(char **input);
t_circ_list	*parsing(char **input);
t_circ_list	*input_to_lst(char **splitted_input);
int			check_sorted(t_circ_list *a);
int			check_almost_sorted(t_circ_list *a);
int			check_duplicate(t_circ_list *lst);
char		**split_input(char **input);

//	utils.c
size_t		strtab_len(char **strtab);
char		**join_strtab(char **stab1, char **stab2);
void		strtab_cat(char **dst, char **src, size_t dst_end);
size_t		get_lst_size(t_circ_list *lst);
void		free_str_tab(char **str_tab);

//	small_sort.c
void		sort_chose(t_lists *lists);
void		sort_3(t_lists *lists);
void		sort_3_next(t_circ_list *a, t_move_list *move_list);
void		sort_5(t_lists *lists);
void		sort_5_r_or_rr(t_lists *lists, int min);

//	index_functions.c
void		put_index(t_circ_list *a);
int			get_min_value(t_circ_list *a);
int			get_max_value(t_circ_list *a);
int			get_max_index(t_circ_list *a);
int			get_min_index(t_circ_list *a);
t_circ_list	*find_elem_index(t_circ_list *lst, int index);
int			find_next_content(t_circ_list *a, int prev_content);

//	rotation_functions.c
void		rot_up_a(t_circ_list *elem, t_circ_list *a, t_move_list *move_list);
void		rot_up_b(t_circ_list *elem, t_circ_list *b, t_move_list *move_list);
void		rot_down_a(t_circ_list *elem, t_circ_list *a,
				t_move_list *move_list);
void		rot_down_b(t_circ_list *elem, t_circ_list *b,
				t_move_list *move_list);
//	sort_last_chunk.c
void		sort_last_chunk(t_lists *lists);

//	big_sort.c
void		big_sort(t_lists *lists, int chunk_nb);
void		partitioning(t_lists *lists, int max_chunk, int pivot);
t_circ_list	*put_elem_top(t_circ_list *a, int max_chunk,
				t_move_list *move_list);
t_circ_list	*get_hold_first(t_circ_list *a, int max_chunk);
t_circ_list	*get_hold_second(t_circ_list *a, int max_chunk);
int			nb_to_top(t_circ_list *elem, t_circ_list *lst);
int			nb_to_bottom(t_circ_list *elem, t_circ_list *lst);
void		get_min_to_top(t_circ_list *lst, char lst_name,
				t_move_list *move_list);
void		get_max_to_top(t_circ_list *lst, char lst_name,
				t_move_list *move_list);

#endif
