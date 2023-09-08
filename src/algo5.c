/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:11:00 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/08 14:19:56 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *stack_a)
{
	t_list	*cursor;

	cursor = stack_a;
	while (cursor->next)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	ft_find_smaller(t_list *stack)
{
	t_list	*cursor;
	t_list	*smaller;
	int		counter;

	cursor = stack;
	smaller = stack;
	counter = 0;
	while (cursor)
	{
		if (cursor->content < smaller->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	cursor = stack;
	while (cursor != smaller)
	{
		counter++;
		cursor = cursor->next;
	}
	return (counter);
}

void	ft_do_push(t_list **stack_a, t_list **stack_b, int counter, int o)
{
	if (counter > 2)
	{
		if (o == 1)
			counter = 5 - counter;
		else
			counter = 4 - counter;
		while (counter)
		{
			reverse_rotate(stack_a, 1);
			counter--;
		}
	}
	else
	{
		while (counter)
		{
			rotate(stack_a, 1);
			counter--;
		}
	}
	push(stack_a, stack_b, 1);
}

void	algo5(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor;
	int		counter;

	cursor = *stack_a;
	if (ft_lstsize(*stack_a) == 5)
	{
		counter = ft_find_smaller(cursor);
		ft_do_push(stack_a, stack_b, counter, 1);
		cursor = *stack_a;
	}
	counter = ft_find_smaller(cursor);
	ft_do_push(stack_a, stack_b, counter, 2);
	if (!(ft_issorted(*stack_a)))
		choose_case(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 2);
}
