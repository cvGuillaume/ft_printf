/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:49:50 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:49:52 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_pct(t_flags *param)
{
	char c;

	c = ' ';
	if (param->padding == '0')
		c = '0';
	while (param->width > 1 && param->padding != ' ')
	{
		param->ret += ft_putchar(c);
		param->width--;
	}
	param->ret += ft_putchar('%');
	while (param->width > 1)
	{
		param->ret += ft_putchar(c);
		param->width--;
	}
}
