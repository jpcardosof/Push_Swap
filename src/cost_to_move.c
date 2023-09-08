/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:29 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/20 01:37:16 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_spot(t_list *stack_a, t_list *stack_b)
{
	t_list	*c_a;
	int		c_b;

	c_a = stack_a;
	c_b = stack_b->content;
	if (c_b > ft_lstlast(stack_a)->content
		&& last_great(&stack_a) == ft_lstlast(stack_a))
		return (c_a);
	if (c_b < ft_smaller(stack_a)->content)
	{
		c_a = ft_smaller(stack_a);
		return (c_a);
	}
	if (c_a->content > c_b && ft_lstlast(stack_a)->content < c_b)
		return (c_a);
	if (c_b > last_great(&stack_a)->content)
	{
		c_a = last_great(&stack_a)->next;
		return (c_a);
	}
	while (!(c_a->content < c_b && c_a->next->content > c_b))
		c_a = c_a->next;
	while (c_a->content < c_b)
		c_a = c_a->next;
	return (c_a);
}

int	ft_cost_r(t_list *stack_a, t_list *spot)
{
	return (ft_lstsize(stack_a) - ft_lstsize(spot));
}

int	ft_cost_rr(t_list *spot)
{
	return (ft_lstsize(spot));
}

t_list	*last_great(t_list **stack_a)
{
	t_list	*greatest;
	t_list	*cursor;

	cursor = *stack_a;
	greatest = cursor;
	while (cursor)
	{
		if (cursor->content > greatest->content)
			greatest = cursor;
		cursor = cursor->next;
	}
	return (greatest);
}

void	final_sort(t_list **stack_a, int ac)
{
	if (ft_lstsize(last_great(stack_a)) > ac / 2)
		while (!(ft_issorted(*stack_a)))
			rotate(stack_a, 1);
	else
		while (!(ft_issorted(*stack_a)))
			reverse_rotate(stack_a, 1);
}
