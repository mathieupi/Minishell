/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:09:46 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 00:10:04 by bledda           ###   ########.fr       */
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
