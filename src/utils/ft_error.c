/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:00:26 by bledda            #+#    #+#             */
/*   Updated: 2021/07/11 18:02:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

void	ft_error(char *msg, char *error_msg)
{
	g_global.return_code = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putchar_fd('\n', 2);
}

void	ft_error2(char *msg, char *msg2, char *error_msg)
{
	g_global.return_code = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putchar_fd('\n', 2);
}
