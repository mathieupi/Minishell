/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:29:36 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:29:36 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if (*(unsigned char *)(dst++) == (unsigned char)c)
			return (dst);
		src++;
	}
	return (0);
}
