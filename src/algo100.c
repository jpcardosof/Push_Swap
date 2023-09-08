/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:33:00 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/21 12:52:35 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_array(int **list, int size)
{
	int	i;
	int	a;
	int	temp;

	a = 1;
	while (a > 0)
	{
		a = 0;
		i = 0;
		while (i < (size - 1))
		{
			if ((*list)[i] > (*list)[i + 1])
			{
				temp = (*list)[i];
				(*list)[i] = (*list)[i + 1];
				(*list)[i + 1] = temp;
				a++;
			}
			i++;
		}
	}
}

int	*ft_create_array(t_list **stack_a, int size)
{
	int		*list;
	int		index;
	t_list	*cursor;

	list = malloc(size * sizeof(int));
	cursor = *stack_a;
	index = 0;
	while (cursor)
	{
		list[index] = cursor->content;
		index++;
		cursor = cursor->next;
	}
	ft_sort_array(&list, size);
	return (list);
}

int	num_of_chunks(int size)
{
	int	num_chuncks;

	num_chuncks = 1;
	if (size == 100)
		num_chuncks = 2;
	else if (size == 500)
		num_chuncks = 5;
	return (num_chuncks);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*spot;

	b = look_the_best(stack_a, stack_b);
	spot = find_spot(*stack_a, b);
	while (*stack_b != b || *stack_a != spot)
	{
		joint_moves(stack_a, stack_b, spot, b);
		while (b != *stack_b)
		{
			if (ft_cost_r(*stack_b, b) > ft_cost_rr(b))
				while (*stack_b != b)
					reverse_rotate(stack_b, 2);
			else
				while (*stack_b != b)
					rotate(stack_b, 2);
		}
		if (ft_cost_r(*stack_a, spot) > ft_cost_rr(spot))
			while (*stack_a != spot)
				reverse_rotate(stack_a, 1);
		else
			while (*stack_a != spot)
				rotate(stack_a, 1);
	}
	push(stack_b, stack_a, 2);
}

void	algo100(t_list **stack_a, t_list **stack_b, int ac)
{
	int		*list;
	int		len_ch;
	int		max;
	t_chunk	chunk;

	len_ch = ft_lstsize(*stack_a) / num_of_chunks(ft_lstsize(*stack_a));
	list = ft_create_array(stack_a, ac);
	max = ft_lstsize(*stack_a);
	increment_chunk(&chunk, list, len_ch, 1);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (exist_chunk(stack_a, chunk))
			push_chunk(stack_a, stack_b, chunk, num_of_chunks(max));
		else
			increment_chunk(&chunk, list, len_ch, 2);
	}
	free(list);
	if (!(ft_issorted(*stack_a)))
		choose_case(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		push_back_to_a(stack_a, stack_b);
	if (!(ft_issorted(*stack_a)))
		final_sort(stack_a, ac);
}
