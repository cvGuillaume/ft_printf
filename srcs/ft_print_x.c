/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:17 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:50:18 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_treat_no_precision(t_flags *flags, unsigned int nbr, int sz)
{
	if (flags->padding == ' ')
	{
		ft_print_hexa(flags, nbr);
		while (flags->width-- > sz)
			flags->ret += ft_putchar(' ');
	}
	else if (flags->padding == '0')
	{
		while (flags->width-- > sz)
			flags->ret += ft_putchar('0');
		ft_print_hexa(flags, nbr);
	}
}

static void		ft_treat_width(t_flags *flags, unsigned int nbr, int sz,
				int count_precision)
{
	if (flags->padding == ' ')
	{
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_print_hexa(flags, nbr);
	}
	while (flags->width - flags->precision > 0 && sz < flags->width)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	if (flags->padding == '0' || !flags->padding)
	{
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_print_hexa(flags, nbr);
	}
}

static void		ft_treat_precision(t_flags *flags, unsigned int nbr, int sz,
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
		while (count_precision-- > 0)
			flags->ret += ft_putchar('0');
		ft_print_hexa(flags, nbr);
	}
	else
		ft_treat_width(flags, nbr, sz, count_precision);
}

void			ft_print_x(t_flags *flags)
{
	unsigned int	nbr;
	int				sz;
	int				count_precision;

	sz = 0;
	nbr = va_arg(flags->ap, unsigned int);
	ft_size_16(nbr, &sz);
	if (flags->type == 'X')
		ft_strlcpy(flags->base, "0123456789ABCDEF", 17);
	if (flags->precision >= 0)
		count_precision = flags->precision - sz;
	if (flags->precision < 0)
		ft_treat_no_precision(flags, nbr, sz);
	if (sz >= flags->width && flags->precision < 0 && !flags->padding)
		ft_print_hexa(flags, nbr);
	while (flags->precision < 0 && !flags->padding && flags->width > sz)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
		if (flags->width == sz)
			ft_print_hexa(flags, nbr);
	}
	if (flags->precision >= 0)
		ft_treat_precision(flags, nbr, sz, count_precision);
}
