/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:30:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/07 12:29:29 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ss;

	if (!s)
		return (0);
	ss = (char *)s;
	while (*ss != (char)c)
	{
		if (*ss == 0)
			return (0);
		ss++;
	}
	return (ss);
}
