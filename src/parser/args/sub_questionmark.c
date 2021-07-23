/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_questionmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:45:16 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/23 14:50:05 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	sub_questionmark(char **arg)
{
	char	*tmp;
	char	*code_str;
	int		i;

	tmp = *arg;
	while (tmp && *tmp)
	{
		tmp = ft_strchr(tmp, '$');
		i = tmp - *arg;
		if (!tmp)
			return ;
		if (*arg[0] != '\'' && !is_inhibited(*arg, i))
		{
			code_str = ft_itoa(g_global.return_code);
			ft_replace_str(arg, i, i + 1, code_str);
			free(code_str);
		}
		tmp = *arg + i + 1;
	}
}
