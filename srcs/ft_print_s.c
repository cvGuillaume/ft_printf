/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:02 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:50:04 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size_char_ptr(t_flags *flags, char *str)
{
	if (flags->precision < 0 || flags->precision >= (int)ft_strlen(str))
		return (ft_strlen(str));
	return (flags->precision);
}

static void		ft_treat_minus_padding(t_flags *flags, char *str, int sz)
{
	while (flags->padding == ' ' && sz > 0)
	{
		flags->ret += ft_putchar(*str);
		sz--;
		str++;
	}
	while (flags->width-- > 0 && flags->padding == ' ')
		flags->ret += ft_putchar(' ');
}

static void		ft_treat_0_padding(t_flags *flags, char *str, int sz)
{
	while (flags->width-- > 0 && flags->padding == '0')
		flags->ret += ft_putchar('0');
	while (flags->padding == '0' && sz > 0)
	{
		flags->ret += ft_putchar(*str);
		sz--;
		str++;
	}
}

void			ft_print_s(t_flags *flags)
{
	char	*str;
	int		sz;

	str = va_arg(flags->ap, char*);
	if (!str)
		str = flags->null;
	sz = ft_size_char_ptr(flags, str);
	flags->width = flags->width - sz;
	while (!flags->padding && flags->width > 0)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	if (flags->padding == ' ')
		ft_treat_minus_padding(flags, str, sz);
	if (flags->padding == '0')
		ft_treat_0_padding(flags, str, sz);
	while (!flags->padding && sz > 0)
	{
		flags->ret += ft_putchar(*str);
		sz--;
		str++;
	}
}
