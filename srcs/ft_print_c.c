/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:49:18 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:49:20 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_print_c(t_flags *flags)
{
	while (!flags->padding && flags->width > 1)
	{
		flags->ret += ft_putchar(' ');
		flags->width--;
	}
	flags->ret += ft_putchar(va_arg(flags->ap, int));
	while (flags->padding && flags->width > 1)
	{
		if (flags->padding == '0')
			flags->ret += ft_putchar('0');
		else if (flags->padding == ' ')
			flags->ret += ft_putchar(' ');
		flags->width--;
	}
}
