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
    t_parsing	parsing;
    int			i;
    bool		sea;

    i = 0;
    parsing = (t_parsing){0};
    sea = true;
    while (*str)
    {
        update_struct(*str, &parsing);
        if (!sea && !parsing.in_dquote && !parsing.in_squote && *str == ' ')
            sea = true;
        if (sea && *str != ' ')
        {
            sea = false;
            i++;
        }
        str++;
    }
    return (i);
}

int ft_isutil(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

char	**split_args(char *str, int ac)
{
	char		**args;
	t_parsing	parsing;
	int			i;
	char		*tmp;
	bool		sea;

	sea = true;
	tmp = 0;
	args = ft_calloc(sizeof(char *), ac + 1);
	i = 0;
	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct(*str, &parsing);
        if (!sea && !parsing.in_dquote && !parsing.in_squote && *str == ' ')
        {
        	if (ft_isutil(tmp))
        	{
				args[i] = ft_strdup(tmp);
				free(tmp);
				tmp = 0;
	            sea = true;
	            i++;
	        }
        }
        if (sea && *str != ' ')
            sea = false;
        add_char(&tmp, *str);
		str++;
		if (*str == 0 && ft_streql(args[i], tmp) == false)
		{
			if (ft_isutil(tmp))
        	{
			 	args[i] = ft_strdup(tmp);
			 	free(tmp);
			 	tmp = 0;
			}
		}
	}
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
	print_array(pars);
	return (pars);
}
