/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:20:29 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/17 14:20:57 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	ft_replace_str(char **arg, unsigned int start_index,
	unsigned int end_index, char *value)
{
	char	*pre;
	char	*post;

	if (start_index > end_index)
		return ;
	if (start_index >= ft_strlen(*arg) || end_index >= ft_strlen(*arg))
		return ;
	pre = ft_substr(*arg, 0, start_index);
	post = ft_substr(*arg, end_index + 1, ft_strlen(*arg));
	add_value(&pre, value);
	add_value(&pre, post);
	free(*arg);
	free(post);
	*arg = pre;
}
