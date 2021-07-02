/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:32:17 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:32:18 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	flen;

	flen = ft_strlen(s);
	if (start > flen)
		return (0);
	flen -= start;
	if (flen > len)
		flen = len;
	p = malloc(flen + 1);
	if (!p)
		return (0);
	ft_strlcpy(p, s + start, flen + 1);
	return (p);
}
