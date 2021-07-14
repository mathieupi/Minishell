/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 08:33:37 by bledda           ###   ########.fr       */
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

void	clean_arg(char **arg)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(*arg, " ");
	free(*arg);
	*arg = ft_strdup(tmp);
	free(tmp);
	tmp = 0;
	if (*arg[0] == '"' && *arg[ft_strlen(*arg) - 1] == '"'
		&& ft_count_char(*arg, '$') > 0)
	{
		i = 0;
		while (*arg[i] != '$')
			i++;
		if (*arg[i] == '$')
		{
			i++;
			while (ft_isspace(*arg[i]) == 0)
			{
				add_char(&tmp, *arg[i])
				i++;
			}
			if (ft_strlen(tmp) > 1)
				ft_replace_str(arg, tmp, ft_getenv(tmp));
			free(tmp);
		}
	}
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
		clean_arg(&pars[i]);
	print_array(pars);
	return (pars);
}
