/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:10:50 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 17:54:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

int	ft_count_char(char *str, char c)
{
	int	j;

	j = 0;
	while (*str)
	{
		if (*str == c)
			j++;
		str++;
	}
	return (j);
}

char	*get_pwd(void)
{
	char	buffer[4096];

	if (getcwd(buffer, 4096) == 0)
		exit(EXIT_FAILURE);
	return (ft_strdup(buffer));
}
