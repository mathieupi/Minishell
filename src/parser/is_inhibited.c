/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inhibited.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:32:58 by bledda            #+#    #+#             */
/*   Updated: 2021/07/15 22:33:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

bool	is_inhibited(const char *str, int char_index)
{
	if (char_index <= 0)
		return (false);
	if (ft_strlen(str) >= (unsigned int) char_index)
		return (false);
	return (str[char_index - 1] == '\\');
}
