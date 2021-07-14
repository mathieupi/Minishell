/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:49 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 06:24:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	add_char(char **str, char c)
{
	char	*tmp;
	char	*tmp_c;

	tmp_c = ft_calloc(sizeof(char), 2);
	tmp_c[0] = c;
	tmp = ft_strjoin(*str, tmp_c);
	free(*str);
	free(tmp_c);
	*str = tmp;
}
