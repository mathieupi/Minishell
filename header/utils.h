/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 06:24:22 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/06 21:28:26 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "minishell.h"

bool	ft_streql(const char *s1, const char *s2);
void	ft_error(char *msg, char *error_msg, int error_code);
void	ft_error2(char *msg, char *msg2, char *error_msg, int error_code);
void	add_value(char **str, char *new_value);
int		count_array(char **arr);
void	free_array(char **arr);
size_t	ft_count_char(const char *str, char c);
char	*get_pwd(void);
void	ft_prompt(char **prompt);
int		ft_clean_input(char **in);
void	try_exec(char **argv);
char	*ft_getenv(char *str);
void	ft_safe_free(void **p);
void	print_array(char **arr);
int		ft_strcheckunset(const char *str);
int		ft_checkunset(char c);
void	update_env(char *env, char *new_value);
char	**ft_get_paths(void);
bool	is_suffix(char *str, char *suffix);
void	ft_replace(char **p, char *new_str);
bool	ft_strisdigit(char *str);
int		ft_max(int a, int b);

int		ft_append_file(char *str, bool should_close);
int		ft_create_file(char *str, bool should_close);
int		ft_open_file(char *str);

#endif
