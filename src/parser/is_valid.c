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
	t_parsing	parsing2;

	parsing = (t_parsing){0};
	parsing2 = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
		update_struct2(*str, &parsing2);
		// printf("%c %d %d %d\n", *str, parsing.inhibited, parsing.in_squote, parsing.in_dquote);
		printf("%c %d %d %d\n", *str, parsing2.inhibited, parsing2.in_squote, parsing2.in_dquote);
		str++;
	}
	//printf("%c %d %d %d\n", *str, parsing.inhibited, parsing.in_squote, parsing.in_dquote);
	return (!parsing.in_dquote && !parsing.in_squote && !parsing.inhibited);
}
