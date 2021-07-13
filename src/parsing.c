/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:56:15 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 14:42:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	**parsing(char *str)
{
	char	**pars;

	pars = 0;
	/*
		si \ ne ce trouve pas a la fin
		ou
		si \ n'existe pas et que ' ou " ne sont pas paires
	*/
	if (str[ft_strlen(str) - 1] == '\\'
		|| (ft_count_char(str, '\\') == 0
			&& (ft_count_char(str, '\'') % 2 != 0
				|| ft_count_char(str, '"') % 2 != 0)))
	{
		printf("WTF🥶\n");
		return (0);
	}
	/*
		Pas de char \'"$;*
	*/
	if (ft_count_char(str, '\'') == 0
		&& ft_count_char(str, '"') == 0
		&& ft_count_char(str, '\\') == 0
		&& ft_count_char(str, '$') == 0
		&& ft_count_char(str, ';') == 0
		&& ft_count_char(str, '*') == 0)
		pars = ft_split(str, ' ');
	else
		printf("This case is comming soon\n");
	return (pars);
}
