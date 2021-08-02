/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:57 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:33:11 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

int	count_args(char *str)
{
	t_parsing	pars;
	int			i;

	i = 0;
	pars = (t_parsing){0};
	pars.sp = true;
	while (*str)
	{
		update_struct(*str, &pars);
		if (!pars.sp && !pars.in_dquote && !pars.in_squote && ft_isspace(*str))
			pars.sp = true;
		if (pars.sp && !ft_isspace(*str))
		{
			pars.sp = false;
			i++;
		}
		str++;
	}
	return (i);
}
