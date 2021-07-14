/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 10:31:07 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	print_array(char **arr)
{
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

void	ft_replace_str(char **arg, char *env_name, char *env_value)
{
	char	*tmp;
	char	*pre;
	char	*post;

	tmp = ft_strnstr(*arg, env_name, ft_strlen(*arg));
	pre = ft_substr(*arg, 0, tmp - *arg - 1);
	post = ft_substr(tmp, ft_strlen(env_name),
			ft_strlen(tmp) - ft_strlen(env_name));
	add_value(&pre, env_value);
	add_value(&pre, post);
	free(*arg);
	*arg = ft_strdup(pre);
	free(pre);
	if (env_value != 0)
		free(env_value);
	free(post);
	free(env_name);
}

void	sub_env(char **arg)
{
	char	*tmp;
	char	*env_name;

	env_name = 0;
	if (*arg[0] != '\'' && ft_count_char(*arg, '$') > 0)
	{
		// SI \$ ne foit pas etre affecter
		tmp = ft_strchr(*arg, '$');
		if (!tmp)
			return ;
		tmp++;
		if (ft_isalnum(*tmp))
		{
			while (ft_isalnum(*tmp) && !ft_isspace(*tmp))
			{
				add_char(&env_name, *tmp);
				tmp++;
			}
			ft_replace_str(arg, env_name, ft_getenv(env_name));
		}
		sub_env(arg);
	}
}

void	trim_arg(char **arg)
{
	char	*tmp;

	tmp = ft_strtrim(*arg, " \t\n\v\f\r");
	free(*arg);
	*arg = tmp;
}

char	**parsing(char *str)
{
	char	**pars;
	int		ac;
	int		i;

	if (!is_valid(str))
	{
		printf("ne reviens jamais\n");
		return (NULL);
	}
	ac = count_args(str);
	pars = ft_calloc(sizeof(char *), ac + 1);
	split_args(pars, str);
	i = -1;
	while (pars[++i])
	{
		trim_arg(&pars[i]);
		sub_env(&pars[i]);
	}
	print_array(pars);
	return (pars);
}
