/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:31:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:31:40 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > dstsize)
		return (dstsize + srclen);
	i = 0;
	dst += dstlen;
	while (srclen > i && dstlen + i + 1 < dstsize)
	{
		*(dst++) = *(src++);
		i++;
	}
	*dst = 0;
	return (dstlen + srclen);
}
