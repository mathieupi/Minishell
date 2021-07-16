/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:34:11 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 10:15:41 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

static void	ft_replace_str(char **arg, unsigned int start_index,
	unsigned int end_index, char *value)
{
	char	*pre;
	char	*post;

	if (start_index >= end_index)
		return ;
	if (start_index >= ft_strlen(*arg) || end_index >= ft_strlen(*arg))
		return ;
	pre = ft_substr(*arg, 0, start_index);
	post = ft_substr(*arg, end_index, ft_strlen(*arg));
	add_value(&pre, value);
	add_value(&pre, post);
	free(*arg);
	*arg = ft_strdup(pre);
	free(pre);
	if (value != 0)
		free(value);
	free(post);
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

	tmp = ft_strchr(*arg, '$');
	if (!tmp)
		return ;
	if (*arg[0] != '\'' && !is_inhibited(*arg, tmp - *arg))
	{
		printf("%s\n", "try extract");
		env_name = extract_env_name(tmp);
		if (env_name)
		{
			printf("%s\n", ft_getenv(env_name));
			ft_replace_str(arg, tmp - *arg, tmp - *arg + ft_strlen(env_name) + 1, ft_getenv(env_name));
		}
	}
}
