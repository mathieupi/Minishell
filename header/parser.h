/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:18:53 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/15 11:42:10 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parsing
{
	bool	inhibited;
	bool	in_squote;
	bool	in_dquote;
	bool	sp;
}	t_parsing;

char	**parsing(char *str);
void	update_struct(char c, t_parsing *parsing);
bool	is_valid(char *str);
void	add_char(char **str, char c);
int		count_args(char *str);
bool	ft_isutil(char *str);
void	add_arg(char **arg, char **tmp);
void	split_args(char **args, char *str);

#endif
