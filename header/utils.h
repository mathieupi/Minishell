#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "../libft/libft.h"

bool	ft_streql(const char *s1, const char *s2);
void	ft_error(char *msg, char *error_msg);
void	add_value(char **str, char *new_value);
int		count_array(char **arr);
void	free_array(char **arr);
int		ft_count_char(char *str, char c);
char	*get_pwd(void);

#endif