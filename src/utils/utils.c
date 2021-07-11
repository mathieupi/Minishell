/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 01:43:26 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 20:52:40 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

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

void	ft_prompt(char **prompt)
{
	char	*name;
	char	*logname;
	char	*pwd;

	name = getenv("NAME");
	logname = getenv("LOGNAME");
	pwd = get_pwd();
	*prompt = ft_strdup("(dev)");
	add_value(prompt, GREEN);
	add_value(prompt, logname);
	add_value(prompt, "@");
	add_value(prompt, name);
	add_value(prompt, RESET);
	add_value(prompt, ":");
	add_value(prompt, BLUE);
	add_value(prompt, pwd);
	free(pwd);
	add_value(prompt, RESET);
	add_value(prompt, "$ ");
}
