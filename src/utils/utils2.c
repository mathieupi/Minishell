/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:10:50 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/12 23:36:25 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

size_t	ft_count_char(const char *str, char c)
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
	char	*pwd;

	if (getcwd(buffer, 4096) == 0)
	{		
		pwd = ft_getenv("PWD");
		return (pwd);
	}
	return (ft_strdup(buffer));
}

int	ft_checkunset(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else if (c == '_')
		return (1);
	return (0);
}

int	ft_strcheckunset(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_checkunset(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_safe_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
