/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 05:39:25 by bledda           ###   ########.fr       */
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

bool	dont_care(const char *str)
{
	if (str[ft_strlen(str) - 1] == '\\')
		return (true);
	if (ft_count_char(str, '\'') % 2 != 0 || ft_count_char(str, '\"') % 2 != 0)
		return (true);
	return (false);
}

typedef struct s_parsing
{
	int		i;
	bool	inibiteur;
	bool	in_squote;
	bool	in_dquote;
	bool	sp;
}	t_parsing;

void	update_struct(char c, t_parsing *parsing)
{
	if (!parsing->inibiteur)
	{
		if (c == '\\')
			parsing->inibiteur = true;
		if (c == '"')
			parsing->in_dquote = !parsing->in_dquote;
		if (c == '\'' && !parsing->in_dquote)
			parsing->in_squote = !parsing->in_squote;
	}
	if (parsing->inibiteur)
		parsing->i++;
	if (parsing->i == 2)
	{
		parsing->inibiteur = false;
		parsing->i = 0;
	}
}

bool	is_valid(char *str)
{
	t_parsing	parsing;

	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
		str++;
	}
	return (!parsing.in_dquote && !parsing.in_squote && !parsing.inibiteur);
}

void	add_char(char **str, char c)
{
	char	*tmp;
	char	*tmp_c;

	tmp_c = ft_calloc(sizeof(char), 2);
	tmp_c[0] = c;
	tmp = ft_strjoin(*str, tmp_c);
	free(*str);
	free(tmp_c);
	*str = tmp;
}

int	count_args(char *str)
{
	t_parsing	pars;
	int			i;

	i = 0;
	pars = (t_parsing){0};
	pars.sp = true;
	while (*str)
	{
		update_struct(*str, &pars);
		if (!pars.sp && !pars.in_dquote && !pars.in_squote && ft_isspace(*str))
			pars.sp = true;
		if (pars.sp && !ft_isspace(*str))
		{
			pars.sp = false;
			i++;
		}
		str++;
	}
	return (i);
}

bool	ft_isutil(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (*str);
}

void	add_arg(char **arg, char **tmp)
{
	*arg = ft_strdup(*tmp);
	ft_safe_free((void **)tmp);
}

void	split_args(char **args, char *str)
{
	t_parsing	pars;
	int			i;
	char		*tmp;

	tmp = 0;
	i = 0;
	pars = (t_parsing){0};
	pars.sp = true;
	while (*str)
	{
		update_struct(*str, &pars);
		if (!pars.sp && !pars.in_dquote && !pars.in_squote
			&& ft_isspace(*str) && ft_isutil(tmp))
		{
			add_arg(&args[i], &tmp);
			pars.sp = true;
			i++;
		}
		if (pars.sp && !ft_isspace(*str))
			pars.sp = false;
		add_char(&tmp, *str);
		str++;
		if (*str == 0 && ft_streql(args[i], tmp) == false && ft_isutil(tmp))
			add_arg(&args[i], &tmp);
	}
}

char	**parsing(char *str)
{
	char	**pars;
	int		ac;

	if (!is_valid(str))
	{
		printf("ne reviens jamais\n");
		return (NULL);
	}
	ac = count_args(str);
	pars = ft_calloc(sizeof(char *), ac + 1);
	split_args(pars, str);
	print_array(pars);
	return (pars);
}
