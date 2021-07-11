/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 01:43:26 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 04:07:59 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

bool	ft_streql(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (false);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

void	ft_error(char *msg, char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putchar_fd('\n', 2);
}

void	add_value(char **str, char *new_value)
{
	char	*tmp;

	tmp = ft_strjoin(*str, new_value);
	free(*str);
	*str = tmp;
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
