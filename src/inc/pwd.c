/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/09 02:40:54 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	main(void)
{
	char	buffer[4096];

	if (getcwd(buffer, 4096) == 0)
		exit(EXIT_FAILURE);
	else
		printf ("%s\n", buffer);
	return (0);
}
