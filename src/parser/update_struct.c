/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:22 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 06:25:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	update_struct(char c, t_parsing *parsing)
{
	if (parsing->inhibited)
		parsing->inhibited = false;
	else
	{
		if (c == '\\' && !parsing->in_squote)
			parsing->inhibited = true;
		if (c == '"' && !parsing->in_squote)
			parsing->in_dquote = !parsing->in_dquote;
		if (c == '\'' && !parsing->in_dquote)
			parsing->in_squote = !parsing->in_squote;
	}
}

void	update_struct2(char c, t_parsing *parsing)
{
	static bool	is_inhiber = false;
	static bool	is_simple = false;
	static bool	is_double = false;


	parsing->in_squote = is_simple;
	parsing->in_dquote = is_double;

	if (parsing->inhibited)
		parsing->inhibited = false;
	else if (is_inhiber)
	{
		parsing->inhibited = true;
		is_inhiber = false;
	}
	if (c == '\\' && !parsing->in_squote)
		is_inhiber = true;

	if (c == '\'' && !is_double)
		is_simple = !is_simple;
	if (c == '"' && !is_simple)
		is_double = !is_double;
}
