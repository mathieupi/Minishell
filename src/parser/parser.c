/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 01:48:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

bool	dont_care(const char *str)
{
	if (str[ft_strlen(str) - 1] == '\\')
		return (true);
	if (ft_count_char(str, '\'') % 2 != 0 || ft_count_char(str, '\"') % 2 != 0)
		return (true);
	return (false);
}

char	**parsing(char *str)
{
	char	**pars;

	pars = ft_split(str, ' ');
	return (pars);
}
