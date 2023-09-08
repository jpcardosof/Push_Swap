/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:41:11 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/22 14:12:19 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_steps(t_list **st_a, t_list **st_b, t_list *s, t_list *c)
{
	int	cost;

	if (ft_cost_r(*st_b, c) > ft_cost_rr(c))
	{
		if (ft_cost_r(*st_a, s) > ft_cost_rr(s))
			cost = ft_cost_rr(c) + ft_cost_rr(s);
		else
			cost = ft_cost_rr(c) + ft_cost_r(*st_a, s);
	}
	else
	{
		if (ft_cost_r(*st_a, s) > ft_cost_rr(s))
			cost = ft_cost_r(*st_b, c) + ft_cost_rr(s);
		else
			cost = ft_cost_r(*st_b, c) + ft_cost_r(*st_a, s);
	}
	return (cost);
}

void	joint_moves(t_list **stack_a, t_list **stack_b, t_list *b, t_list *s)
{
	if (*stack_a != s && *stack_b != b)
	{
		if (ft_cost_r(*stack_b, b) > ft_cost_rr(b))
		{
			if (ft_cost_r(*stack_a, s) > ft_cost_rr(s))
				reverse_rotate_all(stack_a, stack_b, 0);
		}
		else
		{
			if (ft_cost_r(*stack_a, s) < ft_cost_rr(s))
				rr(stack_a, stack_b, 0);
		}
	}
}
