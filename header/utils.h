#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "minishell.h"

bool	ft_streql(const char *s1, const char *s2);
void	ft_error(char *msg, char *error_msg);
void	ft_error2(char *msg, char *msg2, char *error_msg);
void	add_value(char **str, char *new_value);
int		count_array(char **arr);
void	free_array(char **arr);
int		ft_count_char(const char *str, char c);
char	*get_pwd(void);
void	ft_prompt(char **prompt);
int		ft_clean_input(char **in);
void	try_exec(char **argv);
char	*ft_getenv(char *str);
void	ft_safe_free(void **p);
void	print_array(char **arr);
int		ft_strcheckunset(const char *str);
int		ft_checkunset(char c);

#endif
