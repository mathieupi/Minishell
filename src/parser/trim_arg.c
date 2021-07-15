/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:32:44 by bledda            #+#    #+#             */
/*   Updated: 2021/07/15 22:32:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	trim_arg(char **arg, const char *set)
{
	char	*tmp;

	tmp = ft_strtrim(*arg, set);
	free(*arg);
	*arg = tmp;
}
