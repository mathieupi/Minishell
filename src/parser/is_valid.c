/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 06:24:44 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

bool	is_valid(char *str)
{
	t_parsing	parsing;

	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
		printf("%c %d %d %d\n", *str, parsing.inhibited, parsing.in_squote, parsing.in_dquote);
		str++;
	}
	//printf("%c %d %d %d\n", *str, parsing.inhibited, parsing.in_squote, parsing.in_dquote);
	return (!parsing.in_dquote && !parsing.in_squote && !parsing.inhibited);
}
