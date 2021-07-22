/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inhibited.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:32:58 by bledda            #+#    #+#             */
/*   Updated: 2021/07/22 20:05:22 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

bool	is_inhibited(const char *str, int char_index)
{
	int	i;
	int	count;

	if (char_index <= 0)
		return (false);
	if (ft_strlen(str) <= (unsigned int) char_index)
		return (false);
	count = 0;
	i = char_index - 1;
	while (i >= 0 && str[i] == '\\')
	{
		count++;
		i--;
	}
	return (count % 2);
}
