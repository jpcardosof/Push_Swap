/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:00:38 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/23 09:48:11 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_check_moves(char *moves, int option)
{
	int	counter;

	if (moves)
	{
		counter = 0;
		if (!(ft_strncmp(moves, "pa\n", 3)) || !(ft_strncmp(moves, "pb\n", 3)))
			counter += 1;
		if (!(ft_strncmp(moves, "ra\n", 3)) || !(ft_strncmp(moves, "rb\n", 3))
			|| !(ft_strncmp(moves, "rr\n", 3)))
			counter += 2;
		if (!(ft_strncmp(moves, "sa\n", 3)) || !(ft_strncmp(moves, "sb\n", 3))
			|| !(ft_strncmp(moves, "ss\n", 3)))
			counter += 3;
		if (!(ft_strncmp(moves, "rra\n", 4)) || !(ft_strncmp(moves, "rrb\n", 4))
			|| !(ft_strncmp(moves, "rrr\n", 4)))
			counter += 4;
		if (counter == 0 && option == 1)
			write(2, "Error\n", 6);
		return (counter);
	}
	return (5);
}

static void	ft_do_moves(char *moves, t_list **stack_a, t_list **stack_b)
{
	int	check;

	check = ft_check_moves(moves, 0);
	if (check == 1)
		move_p(moves, stack_a, stack_b);
	if (check == 2)
		move_r(moves, stack_a, stack_b);
	if (check == 3)
		move_s(moves, stack_a, stack_b);
	if (check == 4)
		move_rr(moves, stack_a, stack_b);
}

static void	check_sort(t_list *stack_a, t_list *stack_b, t_things *things)
{
	if (ft_check_moves((*things).moves, 0) != 0)
	{
		if (ft_issorted(stack_a) && ft_lstsize(stack_b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free((*things).moves);
}

static void	put_stack(t_list **stack_a, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_things	things;

	if (errors(ac, av, 1) || ac < 3)
		return (0);
	things.c = 1;
	things.moves = malloc(5);
	if (!things.moves)
		return (0);
	ft_initialize_lst(&stack_a, &stack_b);
	put_stack(&stack_a, ac, av);
	while (things.c != 0)
	{
		free(things.moves);
		things.moves = get_next_line(0);
		if (ft_check_moves(things.moves, 1) == 0)
			break ;
		ft_do_moves(things.moves, &stack_a, &stack_b);
		if (ft_check_moves(things.moves, 0) == 5 || things.moves == NULL)
			things.c = 0;
	}
	check_sort(stack_a, stack_b, &things);
	ft_clear_all(&stack_a, &stack_a);
	return (0);
}
