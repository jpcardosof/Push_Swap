/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:39:34 by jferreir          #+#    #+#             */
/*   Updated: 2021/10/22 11:26:15 by jferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)(dst);
	s = (char *)(src);
	if (d && s)
	{
		if ((s < d) && (d < (s + len)))
		{
			s += len;
			d += len;
			while (len--)
				*--d = *--s;
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
