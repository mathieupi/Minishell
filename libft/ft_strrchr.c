/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:32:10 by mmehran           #+#    #+#             */
/*   Updated: 2021/03/28 20:32:11 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*ss;
	char	*sr;

	ss = s;
	sr = 0;
	while (*ss)
	{
		if (*ss == (char)c)
			sr = ss;
		ss++;
	}
	if (!c && !sr)
		sr = ss;
	return (sr);
}
