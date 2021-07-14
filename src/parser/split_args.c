/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:24:19 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 06:25:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	split_args(char **args, char *str)
{
	t_parsing	pars;
	int			i;
	char		*tmp;

	tmp = 0;
	i = 0;
	pars = (t_parsing){0};
	pars.sp = true;
	while (*str)
	{
		update_struct(*str, &pars);
		if (!pars.sp && !pars.in_dquote && !pars.in_squote
			&& ft_isspace(*str) && ft_isutil(tmp))
		{
			add_arg(&args[i], &tmp);
			pars.sp = true;
			i++;
		}
		if (pars.sp && !ft_isspace(*str))
			pars.sp = false;
		add_char(&tmp, *str);
		str++;
		if (*str == 0 && ft_streql(args[i], tmp) == false && ft_isutil(tmp))
			add_arg(&args[i], &tmp);
	}
}
