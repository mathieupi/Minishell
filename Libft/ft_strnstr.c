/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:32:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:32:06 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && len >= i + j)
	{
		if (*(needle + j) == 0)
			return ((char *)haystack + i);
		if (*(haystack + i + j) == *(needle + j))
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
