/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:53:47 by jferreir          #+#    #+#             */
/*   Updated: 2022/01/21 20:32:30 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_case(t_list *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->content;
	b = stack->next->content;
	c = stack->next->next->content;
	if (a < b && b > c && a < c)
		return (1);
	if (a > b && b < c && a < c)
		return (2);
	if (a < b && b > c && a > c)
		return (3);
	if (a > b && b > c && c < a)
		return (4);
	if (a > b && b < c && a > c)
		return (5);
	else
		return (0);
}

void	choose_case(t_list **stack_a)
{
	t_list	*cursor;
	int		c;

	cursor = *stack_a;
	c = find_case(cursor);
	if (c == 1)
	{
		reverse_rotate(stack_a, 1);
		swap(stack_a, 1);
	}
	else if (c == 2)
		swap(stack_a, 1);
	else if (c == 3)
		reverse_rotate(stack_a, 1);
	else if (c == 4)
	{
		rotate(stack_a, 1);
		swap(stack_a, 1);
	}
	else
		rotate(stack_a, 1);
}
