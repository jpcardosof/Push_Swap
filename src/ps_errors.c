/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:45:48 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/23 10:50:07 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_doubles(int ac, char **av)
{
	int	index;
	int	cursor;

	index = 1;
	while (index < ac)
	{
		cursor = index + 1;
		while (cursor < ac)
		{
			if (ft_atoi(av[index]) == ft_atoi(av[cursor]))
				return (1);
			cursor++;
		}
		index++;
	}
	return (0);
}

static int	ft_all_integers(int ac, char **av)
{
	int	index;

	index = 1;
	while (index < ac)
	{
		if (ft_atoi(av[index]) < -2147483648 || ft_atoi(av[index]) > 2147483647)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_is_already_sorted(int ac, char **av)
{
	int	index;

	index = 0;
	while (++index < ac - 1)
	{
		if (ft_atoi(av[index]) >= ft_atoi(av[index + 1]))
			return (0);
		else
			continue ;
	}
	return (1);
}

static int	ft_all_numeric(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j])
				|| (av[i][0] == '-' && ft_isdigit(av[i][1])))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	errors(int ac, char **av, int op)
{
	if (ft_doubles(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_all_integers(ac, av) || ft_all_numeric(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_is_already_sorted(ac, av) && op == 1 && ac > 2)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	if (ft_is_already_sorted(ac, av) && op == 2)
		return (1);
	return (0);
}
