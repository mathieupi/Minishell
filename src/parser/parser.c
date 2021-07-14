/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:16:35 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/14 01:48:11 by bledda           ###   ########.fr       */
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

int	count_args(char *str)
{
	t_parsing	parsing;
	int			i;

	i = 1;
	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
		if (!parsing.in_dquote && !parsing.in_squote && *str == ' ')
			i++;
		str++;
	}
	return (i);
}

char	**split_args(char *str, int ac)
{
	char		**args;
	t_parsing	parsing;
	int			i;
	int			j;
	int			tj;

	args = ft_calloc((ac + 1), sizeof(char *));
	i = 0;
	j = 0;
	tj = 0;
	parsing = (t_parsing){0};
	while (str[j])
	{
		update_struct(str[j], &parsing);
		if (!parsing.in_dquote && !parsing.in_squote && str[j] == ' ')
		{
			args[i] = ft_calloc(tj + 1, sizeof(char));
			i++;
			tj = 0;
		}
		tj++;
		j++;
	}
	i = 0;
	j = 0;
	tj = 0;
	parsing = (t_parsing){0};
	while (str[j])
	{
		update_struct(str[j], &parsing);
		if (!parsing.in_dquote && !parsing.in_squote && str[j] == ' ')
		{
			i++;
			//printf("%c", '\n');
			tj = 0;
		}
		args[i][tj] = str[j];
		//printf("%c",  str[j]);
		tj++;
		j++;
	}
	printf("%c", '\n');
	return (args);
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
	pars = split_args(str, ac);
	return (pars);
}
