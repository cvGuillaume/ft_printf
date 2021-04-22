/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:58:15 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:58:18 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_size_10(t_flags *flags, int nbr)
{
	int		i;

	i = 1;
	if (nbr < 0)
		i++;
	if (nbr == 0 && flags->precision == 0)
		return (0);
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		i++;
	}
	flags->ret += i;
	return (i);
}

void		reinit_flags(t_flags *flags)
{
	flags->padding = '\0';
	flags->type = '\0';
	flags->width = 0;
	flags->precision = -1;
	ft_strlcpy(flags->base, "0123456789abcdef", 17);
}

int			ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
