/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:34:11 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 14:31:49 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

static void	ft_replace_str(char **arg, unsigned int start_index,
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

char	*extract_env_name(const char *str)
{
	int		i;
	char	*env_name;

	str++;
	if (*str == 0)
		return (NULL);
	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (!i)
		return (NULL);
	env_name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(env_name, str, i + 1);
	return (env_name);
}

void	sub_env(char **arg)
{
	char	*tmp;
	char	*env_name;
	char	*env_value;
	int		i;

	tmp = *arg;
	while (tmp && *tmp)
	{
		tmp = ft_strchr(tmp, '$');
		i = tmp - *arg;
		if (!tmp)
			return ;
		if (*arg[0] != '\'' && !is_inhibited(*arg, i))
		{
			env_name = extract_env_name(tmp);
			if (env_name)
			{
				env_value = ft_getenv(env_name);
				ft_replace_str(arg, i, i + ft_strlen(env_name), env_value);
				free(env_value);
				free(env_name);
			}
		}
		tmp = *arg + i + 1;
	}
}
