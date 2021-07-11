/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:17:13 by bledda            #+#    #+#             */
/*   Updated: 2021/07/11 18:18:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

char	*ft_remove_char(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(str));
	while (ft_isspace(str[i]) && str[i] != 0)
		i++;
	while (str[i] != 0)
	{
		if (str[i] == '\'' || str[i] == '\\' || str[i] == '"')
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				if (i - 1 >= 0 && str[i - 1] == '\\')
				{
					tmp[j] = str[i];
					j++;
				}
			}
			else
			{
				if (i - 1 >= 0 && (str[i - 1] == '"' || str[i - 1] == '\''))
				{
					tmp[j] = str[i];
					j++;
				}
			}
		}
		else
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	tmp[j] = 0;
	free(str);
	return (tmp);
}

int	ft_clean_input(char **in)
{
	int	size_input;

	size_input = ft_strlen(*in);
	if ((*in)[size_input - 1] == '\\')
	{
		printf("This case should not be managed\n");
		return (0);
	}
	else
		*in = ft_strdup(ft_remove_char(*in));
	return (1);
}
