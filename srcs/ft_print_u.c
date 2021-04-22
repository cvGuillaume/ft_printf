/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:09 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:50:10 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_no_precision(t_flags *flags, unsigned int n, int len)
{
	if (flags->padding == ' ')
	{
		ft_putnbr_fd(n, 1);
		while (flags->width > len)
		{
			flags->ret += ft_putchar(' ');
			flags->width--;
		}
	}
	else if (flags->padding == '0')
	{
		while (flags->width > len)
		{
			flags->ret += ft_putchar('0');
			flags->width--;
		}
		ft_putnbr_fd(n, 1);
	}
}

void	print_rest_u(t_flags *flags, unsigned int n, int displayed_prec)
{
	while (displayed_prec > 0)
	{
		flags->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_putnbr_fd(n, 1);
}

void	ft_treat_width(t_flags *flags, unsigned int n, int len,
		int displayed_prec)
{
	if (flags->padding == ' ')
	{
		while (displayed_prec > 0)
		{
			flags->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	while (flags->width - flags->precision > 0 && len < flags->width)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	if (flags->padding == '0' || !flags->padding)
	{
		print_rest_u(flags, n, displayed_prec);
	}
}

void	ft_treat_precision(t_flags *flags, unsigned int n, int len,
		int displayed_prec)
{
	if (flags->precision == 0 && n == 0)
	{
		while (flags->width > 0)
		{
			flags->ret += ft_putchar(' ');
			flags->width--;
		}
		return ;
	}
	if (flags->precision >= flags->width)
	{
		while (displayed_prec > 0)
		{
			flags->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	else
		ft_treat_width(flags, n, len, displayed_prec);
}

void	ft_print_u(t_flags *flags)
{
	unsigned int	n;
	int				len;
	int				displayed_prec;

	n = va_arg(flags->ap, unsigned int);
	len = ft_u_size_10(flags, n);
	if (n == 0 && flags->precision == 0 && flags->width == 0)
		return ;
	if (flags->precision >= 0)
		displayed_prec = flags->precision - len;
	if (flags->precision < 0)
		ft_treat_no_precision(flags, n, len);
	if (len >= flags->width && flags->precision < 0 && !flags->padding)
		ft_putnbr_fd(n, 1);
	while (flags->precision < 0 && !flags->padding && flags->width > len)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
		if (flags->width == len)
			ft_putnbr_fd(n, 1);
	}
	if (flags->precision >= 0)
		ft_treat_precision(flags, n, len, displayed_prec);
}
