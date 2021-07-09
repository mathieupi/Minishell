/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/09 06:13:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*ft_pwd(void)
{
	char	buffer[4096];
	char	*str;

	str = 0;
	if (getcwd(buffer, 4096) == 0)
		exit(EXIT_FAILURE);
	else
		str = ft_strdup(buffer);
	return (str);
}
