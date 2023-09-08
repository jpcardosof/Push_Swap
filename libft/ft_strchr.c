/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:36:28 by jferreir          #+#    #+#             */
/*   Updated: 2022/02/22 16:07:44 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	if (str)
	{
		index = 0;
		if (str[index] == (char)c)
			return ((char *)str);
		while (str[index++])
			if (str[index] == (char)c)
				return ((char *)str + index);
	}
	return (NULL);
}
