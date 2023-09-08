/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:20:44 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/22 14:12:00 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	rotate(t_list **stack, int option)
{
	t_list	*cursor;
	t_list	*new_start;

	cursor = ft_lstlast(*stack);
	cursor->next = *stack;
	cursor = *stack;
	new_start = (*stack)->next;
	cursor->next = NULL;
	*stack = new_start;
	if (option == 1)
		write(1, "ra\n", 3);
	if (option == 2)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int option)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (option == 0)
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **stack, int option)
{
	t_list	*temp;
	t_list	*new_end;

	temp = *stack;
	temp = ft_lstlast(temp);
	temp->next = *stack;
	new_end = *stack;
	while (new_end->next != temp)
		new_end = new_end->next;
	new_end->next = NULL;
	*stack = temp;
	if (option == 1)
		write(1, "rra\n", 4);
	if (option == 2)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_all(t_list **stack_a, t_list **stack_b, int option)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (option == 0)
		write(1, "rrr\n", 4);
}
