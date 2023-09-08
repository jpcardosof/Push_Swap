/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:33:28 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/22 22:58:55 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	call_case(int ac, t_list **stack_a, t_list **stack_b)
{
	if (ac == 3)
		algo2(stack_a);
	else if (ac == 4)
		choose_case(stack_a);
	else if (ac == 5)
		algo5(stack_a, stack_b);
	else if (ac == 6)
		algo5(stack_a, stack_b);
	else
		algo100(stack_a, stack_b, ac);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (errors(ac, av, 2) || ac < 3)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	put_stack(&stack_a, ac, av);
	call_case(ac, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
