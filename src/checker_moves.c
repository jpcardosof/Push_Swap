/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:47:14 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/22 21:04:28 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_p(char *moves, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(moves, "pb\n", 3)))
		push(stack_a, stack_b, 3);
	else
		push(stack_b, stack_a, 3);
}

void	move_r(char *moves, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(moves, "ra\n", 3)))
		rotate(stack_a, 3);
	else if (!(ft_strncmp(moves, "rb\n", 3)))
		rotate(stack_b, 3);
	else
		rr(stack_a, stack_b, 1);
}

void	move_s(char *moves, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(moves, "sa\n", 3)))
		swap(stack_a, 3);
	else if (!(ft_strncmp(moves, "sb\n", 3)))
		swap(stack_b, 3);
	else
		ss(stack_a, stack_b, 1);
}

void	move_rr(char *moves, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(moves, "rra\n", 4)))
		reverse_rotate(stack_a, 3);
	else if (!(ft_strncmp(moves, "rrb\n", 4)))
		reverse_rotate(stack_b, 3);
	else
		reverse_rotate_all(stack_a, stack_b, 1);
}
