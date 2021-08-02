/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:10:01 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:34:11 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

bool	double_char(char c, char next_c, char *set)
{
	while (*set)
	{
		if (c == *set && next_c == *set)
			return (true);
		set++;
	}
	return (false);
}
