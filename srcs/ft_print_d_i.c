/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:19:14 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:49:31 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_treat_no_precision(t_flags *flags, long int nbr, int sz)
{
	if (flags->padding == ' ')
	{
		ft_putnbr_fd(nbr, 1);
		while (flags->width-- > sz)
			flags->ret += ft_putchar(' ');
	}
	else if (flags->padding == '0')
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (flags->width-- > sz)
			flags->ret += ft_putchar('0');
		ft_putnbr_fd(nbr, 1);
	}
}

static void		ft_print_precision_0s(t_flags *flags, long int nbr,
				int count_precision)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	while (count_precision-- > 0)
		flags->ret += ft_putchar('0');
	ft_putnbr_fd(nbr, 1);
}

static void		ft_treat_width(t_flags *flags, long int nbr, int sz,
				int count_precision)
{
	if (flags->padding == ' ')
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_putnbr_fd(nbr, 1);
	}
	while (flags->width - flags->precision > 0 && sz < flags->width)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	if (flags->padding == '0' || !flags->padding)
		ft_print_precision_0s(flags, nbr, count_precision);
}

static void		ft_treat_precision(t_flags *flags, long int nbr, int sz,
				int count_precision)
{
	if (flags->precision == 0 && nbr == 0)
	{
		while (flags->width-- > 0)
			flags->ret += ft_putchar(' ');
		return ;
	}
	if (flags->precision >= flags->width)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_putnbr_fd(nbr, 1);
	}
	else
		ft_treat_width(flags, nbr, sz, count_precision);
}

void			ft_print_d_i(t_flags *flags)
{
	long int	nbr;
	int			sz;
	int			count_precision;

	nbr = va_arg(flags->ap, int);
	sz = ft_size_10(flags, nbr);
	if (nbr == 0 && flags->precision == 0 && !flags->width)
		return ;
	if (flags->precision >= 0)
		count_precision = ft_get_displayed_precision(flags, nbr, sz);
	if (flags->precision < 0)
		ft_treat_no_precision(flags, nbr, sz);
	if (sz >= flags->width && flags->precision < 0 && !flags->padding)
		ft_putnbr_fd(nbr, 1);
	while (flags->precision < 0 && !flags->padding && flags->width > sz)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
		if (flags->width == sz)
			ft_putnbr_fd(nbr, 1);
	}
	if (flags->precision >= 0)
		ft_treat_precision(flags, nbr, sz, count_precision);
}
