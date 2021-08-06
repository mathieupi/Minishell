/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:18:53 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/06 21:14:24 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
 *	PART ARGS
 */
typedef struct s_parsing
{
	bool	inhibited;
	bool	in_squote;
	bool	in_dquote;
	bool	sp;
	bool	is_inhiber;
	bool	is_simple;
	bool	is_double;
}	t_parsing;

char	**parsing(char *str);
void	update_struct(char c, t_parsing *parsing);
void	update_struct2(char c, t_parsing *parsing);
bool	is_valid(char *str);
void	add_char(char **str, char c);
int		count_args(char *str);
bool	ft_isutil(char *str);
void	add_arg(char **arg, char **tmp);
void	split_args(char **args, char *str);
bool	is_inhibited(const char *str, int char_index);
void	trim_arg(char **arg, const char *set);
void	sub_questionmark(char **arg);
void	sub_env(char **arg);
void	remove_backslash(char **arg);
void	remove_backslash2(char **arg);
void	remove_quote(char **arg);
void	ft_replace_str(char **arg, unsigned int start_index,
			unsigned int end_index, char *value);
void	sub_tilde(char **arg);

# define CHEVRON_LL '<' * '<'
# define CHEVRON_RR '>' * '>'
# define PIPE_PIPE '|' * '|'
# define AND_AND '&' * '&'
/*
 *	PART CMDS
 */
typedef struct s_cmd
{
	int		fin;
	int		fout;
	int		type;
	char	*str;
	char	**args;
}	t_cmd;

t_cmd	**split_cmds(char *str);
void	free_cmds(t_cmd **cmds);
void	try_cmds(t_cmd	**cmds);
void	add_calloc(t_cmd ***cmdsp);
bool	is_in_set(char c, const char *set);
bool	double_char(char c, char next_c, char *set);
bool	cmds_is_valid(t_cmd	**cmds);

/*
* REDIRECION
*/
void	ft_pipe(t_cmd *cmd1, t_cmd *cmd2);
void	multi_pipe(t_cmd **cmds, int *i, int icmd, int ocmd);
void	l_chevron(t_cmd *cmd1, t_cmd *cmd_file);
void	ll_chevron(t_cmd *cmd1, t_cmd *end_keyword);
void	r_chevron(t_cmd *cmd1, t_cmd *cmd_file);
void	rr_chevron(t_cmd *cmd1, t_cmd *cmd_file);
bool	is_simple(t_cmd **cmds, int *j);
void	red_left(t_cmd **cmds, int *i);
bool	red_right(t_cmd **cmds, int *i);
bool	try_right(t_cmd **cmds, int *i);
bool	exec_multi(t_cmd **cmds, int *save_i, int *fin, int *fout);

typedef struct s_fds
{
	int		curr_pipe[2];
	bool	first;
	int		stdin_;
	int		stdout_;
	int		fin;
	int		fout;
}				t_fds;

#endif
