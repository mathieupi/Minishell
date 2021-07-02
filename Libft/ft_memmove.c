/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:30:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:30:06 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		step;

	step = 1;
	i = 0;
	if (dst > src)
	{
		i = len - 1;
		step = -1;
	}
	while (len-- > 0)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i += step;
	}
	return (dst);
}
