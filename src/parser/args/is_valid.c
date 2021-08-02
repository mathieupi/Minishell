/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:30 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:33:28 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

bool	is_valid(char *str)
{
	t_parsing	parsing;

	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
		str++;
	}
	return (!parsing.in_dquote && !parsing.in_squote && !parsing.inhibited);
}
