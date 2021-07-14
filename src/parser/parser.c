/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 06:25:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	print_array(char **arr)
{
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

char	**parsing(char *str)
{
	char	**pars;
	int		ac;

	if (!is_valid(str))
	{
		printf("ne reviens jamais\n");
		return (NULL);
	}
	ac = count_args(str);
	pars = ft_calloc(sizeof(char *), ac + 1);
	split_args(pars, str);
	print_array(pars);
	return (pars);
}
