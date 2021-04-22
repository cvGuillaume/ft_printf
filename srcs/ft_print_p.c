/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:49:38 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:49:40 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_treat_no_precision(t_flags *flags, unsigned long int nbr,
				int sz)
{
	if (sz >= flags->width - 2 && !flags->padding)
		flags->ret += ft_putstr("0x");
	if (sz >= flags->width - 2 && !flags->padding)
		ft_print_hexa_ull(flags, nbr);
	if (flags->padding == ' ')
	{
		flags->ret += ft_putstr("0x");
		ft_print_hexa_ull(flags, nbr);
		while (flags->width - 2 > sz)
		{
			flags->ret += ft_putchar(' ');
			flags->width--;
		}
	}
	else if (flags->padding == '0')
	{
		flags->ret += ft_putstr("0x");
		while (flags->width - 2 > sz)
		{
			flags->ret += ft_putchar('0');
			flags->width--;
		}
		ft_print_hexa_ull(flags, nbr);
	}
}

static void		ft_treat_width(t_flags *flags, unsigned long int nbr, int sz,
				int count_precision)
{
	if (flags->padding == ' ')
	{
		flags->ret += ft_putstr("0x");
		while (count_precision > 0)
		{
			flags->ret += ft_putchar('0');
			count_precision--;
		}
		ft_print_hexa_ull(flags, nbr);
	}
	while (flags->width - 2 - flags->precision > 0 && sz < flags->width - 2)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	if (flags->padding == '0' || !flags->padding)
	{
		flags->ret += ft_putstr("0x");
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_print_hexa_ull(flags, nbr);
	}
}

static void		ft_treat_precision(t_flags *flags, unsigned long int nbr,
				int sz, int count_precision)
{
	if (flags->precision == 0 && nbr == 0)
	{
		if (flags->padding == ' ')
			flags->ret += ft_putstr("0x");
		while (flags->width - 2 > 0)
		{
			flags->ret += ft_putchar(' ');
			flags->width--;
		}
		if (flags->padding != ' ')
			flags->ret += ft_putstr("0x");
		return ;
	}
	if (flags->precision >= flags->width)
	{
		flags->ret += ft_putstr("0x");
		while (count_precision > 0)
		{
			flags->ret += ft_putchar('0');
			count_precision--;
		}
		ft_print_hexa_ull(flags, nbr);
	}
	else
		ft_treat_width(flags, nbr, sz, count_precision);
}

void			ft_print_p(t_flags *flags)
{
	unsigned long long	nbr;
	int					sz;
	int					count_precision;

	sz = 0;
	nbr = va_arg(flags->ap, unsigned long long);
	ft_size_16_ull(nbr, &sz);
	if (flags->precision >= 0)
		count_precision = flags->precision - sz;
	if (flags->precision < 0)
		ft_treat_no_precision(flags, nbr, sz);
	while (flags->precision < 0 && !flags->padding && flags->width - 2 > sz)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
		if (flags->width - 2 == sz)
		{
			flags->ret += ft_putstr("0x");
			ft_print_hexa_ull(flags, nbr);
		}
	}
	if (flags->precision >= 0)
		ft_treat_precision(flags, nbr, sz, count_precision);
}
