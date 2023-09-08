/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:32:56 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/23 09:34:07 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_chunk
{
	int		min_ch;
	int		max_ch;
	int		i_max;
	int		i_min;
}			t_chunk;

int		num_of_chunks(int size);
int		ft_cost_rr(t_list *spot);
int		ft_issorted(t_list *stack_a);
int		ft_find_smaller(t_list *stack);
int		ft_find_quarter(t_list **stack_a);
int		errors(int ac, char **av, int op);
int		*ft_sort(t_list **stack_a, int ac);
int		ft_cost_r(t_list *stack_a, t_list *spot);
int		exist_chunk(t_list **stack_a, t_chunk ch);
int		calculate_steps(t_list **st_a, t_list **st_b, t_list *s, t_list *c);

void	algo2(t_list **stack_a);
void	choose_case(t_list **stack_a);
void	swap(t_list **stack, int option);
void	rotate(t_list **stack, int option);
void	final_sort(t_list **stack_a, int ac);
void	algo5(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, int option);
void	push(t_list **src, t_list **dest, int option);
void	ss(t_list **stack_a, t_list **stack_b, int option);
void	rr(t_list **stack_a, t_list **stack_b, int option);
void	algo100(t_list **stack_a, t_list **stack_b, int ac);
void	increment_chunk(t_chunk *chunk, int *list, int len, int option);
void	reverse_rotate_all(t_list **stack_a, t_list **stack_b, int option);
void	push_chunk(t_list **stack_a, t_list **stack_b, t_chunk ch, int nb);
void	ft_do_push(t_list **stack_a, t_list **stack_b, int counter, int o);
void	joint_moves(t_list **stack_a, t_list **stack_b, t_list *b, t_list *s);

t_list	*ft_smaller(t_list *stack_a);
t_list	*last_great(t_list **stack_a);
t_list	*find_spot(t_list *stack_a, t_list *stack_b);
t_list	*look_the_best(t_list **stack_a, t_list **stack_b);

/*
 *BONUS
 */

typedef struct s_things
{
	int		c;
	char	*moves;
}	t_things;

void	free_moves(t_things *things);
void	ft_clear_all(t_list **stack_a, t_list **stack_b);
void	ft_initialize_lst(t_list **stack_a, t_list **stack_b);
void	move_p(char *moves, t_list **stack_a, t_list **stack_b);
void	move_r(char *moves, t_list **stack_a, t_list **stack_b);
void	move_s(char *moves, t_list **stack_a, t_list **stack_b);
void	move_rr(char *moves, t_list **stack_a, t_list **stack_b);

#endif