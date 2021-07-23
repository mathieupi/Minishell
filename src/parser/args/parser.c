/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/23 15:13:44 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

char	**parsing(char *str)
{
	char	**pars;
	int		ac;
	int		i;

	if (!is_valid(str))
	{
		printf("Comeback in 7.5 million years 🕰\n");
		return (NULL);
	}
	ac = count_args(str);
	pars = ft_calloc(sizeof(char *), ac + 1);
	split_args(pars, str);
	i = -1;
	while (pars[++i])
	{
		trim_arg(&pars[i], " \t\n\v\f\r");
		sub_env(&pars[i]);
		sub_questionmark(&pars[i]);
		sub_tilde(&pars[i]);
		remove_backslash(&pars[i]);
		remove_quote(&pars[i]);
	}
	return (pars);
}
