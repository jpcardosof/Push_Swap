/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:31:59 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/21 12:58:55 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_smaller(t_list *stack_a)
{
	t_list	*cursor;
	t_list	*smaller;

	cursor = stack_a;
	smaller = cursor;
	while (cursor)
	{
		if (cursor->content < smaller->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	return (smaller);
}

int	exist_chunk(t_list **stack_a, t_chunk ch)
{
	t_list	*cursor;

	cursor = *stack_a;
	while (cursor)
	{
		if (cursor->content >= ch.min_ch && cursor->content <= ch.max_ch)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

void	increment_chunk(t_chunk *chunk, int *list, int len, int option)
{
	if (option == 1)
	{
		chunk->i_min = 0;
		chunk->i_max = len;
	}
	else
	{
		chunk->i_min += len;
		chunk->i_max = chunk->i_min + len;
	}
	chunk->min_ch = list[chunk->i_min];
	chunk->max_ch = list[chunk->i_max];
}

void	push_chunk(t_list **stack_a, t_list **stack_b, t_chunk ch, int nb)
{
	if (*stack_a)
	{
		if ((*stack_a)->content >= ch.min_ch
			&& (*stack_a)->content <= ch.max_ch)
			push(stack_a, stack_b, 1);
		else
		{
			if (nb == 2)
			{
				push(stack_a, stack_b, 1);
				rotate(stack_b, 2);
			}
			else
				rotate(stack_a, 1);
		}
	}
}

t_list	*look_the_best(t_list **stack_a, t_list **stack_b)
{
	t_list	*c;
	t_list	*sp_c;
	t_list	*b;
	t_list	*sp_b;

	c = *stack_b;
	b = *stack_b;
	sp_b = find_spot(*stack_a, b);
	while (c)
	{
		sp_c = find_spot(*stack_a, c);
		if (calculate_steps(stack_a, stack_b, sp_c, c)
			< calculate_steps(stack_a, stack_b, sp_b, b))
		{
			b = c;
			sp_b = sp_c;
		}
		c = c->next;
	}
	return (b);
}
