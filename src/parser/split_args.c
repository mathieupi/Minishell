/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:24:19 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 07:29:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

// +!pars->inhibited
static int	step_first(t_parsing *pars, char str_c, char **tmp, char **arg)
{
	if (!pars->inhibited && !pars->sp
		&& !pars->in_dquote && !pars->in_squote && ft_isspace(str_c))
	{
		if (ft_isutil(*tmp))
		{
			add_arg(arg, tmp);
			pars->sp = true;
			return (1);
		}
		else
			free(tmp);
	}
	return (0);
}

static void	step_end(char str_c, char **arg, char **tmp)
{
	if (str_c == 0 && ft_streql(*arg, *tmp) == false)
	{
		if (ft_isutil(*tmp))
			add_arg(arg, tmp);
		else
			free(*tmp);
	}
}

//update struct 2 peux faire de la merde je sais pas trop
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
		update_struct2(*str, &pars);
		if (step_first(&pars, *str, &tmp, &args[i]))
			i++;
		if (pars.sp && !ft_isspace(*str))
			pars.sp = false;
		add_char(&tmp, *str);
		str++;
		step_end(*str, &args[i], &tmp);
	}
}
