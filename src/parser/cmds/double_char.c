/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:10:01 by bledda            #+#    #+#             */
/*   Updated: 2021/07/22 23:10:49 by bledda           ###   ########.fr       */
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
