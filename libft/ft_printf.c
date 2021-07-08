/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 05:12:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/23 05:31:07 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_spe	parse_spe(const char *format)
{
	t_spe	spe;

	spe = (t_spe){0};
	format++;
	spe.type = *format;
	spe.size = 2;
	return (spe);
}

static int	print_str(const char *str)
{
	ft_putstr_fd((char *)str, 1);
	return (ft_strlen(str));
}

static int	print_nbr(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_nbrlen(nbr));
}

static int	print_spe(t_spe *spe, va_list argptr)
{
	int	count;

	count = 0;
	if (spe->type == 'c')
	{
		ft_putchar_fd(va_arg(argptr, int), 1);
		count = 1;
	}
	if (spe->type == 's')
		count = print_str(va_arg(argptr, char *));
	if (spe->type == 'd')
		count = print_nbr(va_arg(argptr, int));
	return (count);
}

/*
	This is a simplified printf that only deal with conversion
	(no flags nothing fancy)
	conversion spe should be (%c, %s, %d)
*/
int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	argptr;
	t_spe	spe;

	va_start(argptr, format);
	count = 0;
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
			format++;
		}
		else
		{
			spe = parse_spe(format);
			count += print_spe(&spe, argptr);
			format += spe.size;
		}
	}
	va_end(argptr);
	return (count);
}
