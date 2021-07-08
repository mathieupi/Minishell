/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:31:59 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:32:00 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	char	*pp;

	p = malloc(ft_strlen(s) + 1);
	pp = p;
	while (*s)
	{
		*p = (*f)(p - pp, *s);
		p++;
		s++;
	}
	*p = 0;
	return (pp);
}
