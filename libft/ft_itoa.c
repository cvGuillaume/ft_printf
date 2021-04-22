/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:56:45 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/26 19:48:12 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_int_10(long nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long	nbr;
	int		i;
	char	*res;

	nbr = n;
	i = ft_size_int_10(nbr);
	if (!(res = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	res[--i] = '\0';
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		res[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	return (res);
}
