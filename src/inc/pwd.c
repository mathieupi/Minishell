/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:35:03 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_pwd(void)
{
	char	buffer[4096];

	if (getcwd(buffer, 4096) == 0)
		exit(EXIT_FAILURE);
	printf("%s\n", buffer);
	g_global.return_code = 0;
}
