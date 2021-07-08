/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 05:12:21 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/23 05:12:22 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long nbr)
{
	int	result;

	result = 0;
	if (nbr <= 0)
		result++;
	while (nbr)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}
