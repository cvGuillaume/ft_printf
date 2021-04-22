/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:58:05 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:58:07 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_u_size_10(t_flags *flags, long int nbr)
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

void		ft_size_16(unsigned long int n, int *hexa_len)
{
	if (n >= 16)
		ft_size_16((unsigned long int)(n / 16), hexa_len);
	*hexa_len = *hexa_len + 1;
}

void		ft_print_hexa(t_flags *flags, unsigned int nbr)
{
	if (nbr >= 16)
		ft_print_hexa(flags, (unsigned int)nbr / 16);
	flags->ret += ft_putchar(flags->base[nbr % 16]);
}

void		ft_print_hexa_ull(t_flags *flags, unsigned long long nbr)
{
	if (nbr >= 16)
		ft_print_hexa_ull(flags, nbr / 16);
	flags->ret += ft_putchar(flags->base[nbr % 16]);
}

void		ft_size_16_ull(unsigned long long n, int *hexa_len)
{
	if (n >= 16)
		ft_size_16((n / 16), hexa_len);
	*hexa_len = *hexa_len + 1;
}
