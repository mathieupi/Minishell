/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:09:46 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:34:15 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

bool	isset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}
