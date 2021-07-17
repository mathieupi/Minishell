/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:19:51 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/17 17:29:38 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	sub_tilde(char **arg)
{
	char	*tmp;

	if ((*arg)[0] == 0 || (*arg)[0] == '\'' || (*arg)[0] == '"')
		return ;
	if ((*arg)[0] == '~' && (*arg)[1] != '~')
	{
		tmp = ft_getenv("HOME");
		ft_replace_str(arg, 0, 0, tmp);
		free(tmp);
	}
}
