/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:26 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:50:27 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_type(t_flags *flags)
{
	return (flags->type == 'c' || flags->type == 's' || flags->type == 'p' ||
			flags->type == 'd' || flags->type == 'i' || flags->type == 'u' ||
			flags->type == 'x' || flags->type == 'X' || flags->type == '%');
}

void		ft_parse_padding(const char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] == '0')
	{
		flags->padding = '0';
		i++;
	}
	while (str[i] == '-')
	{
		flags->padding = ' ';
		i++;
	}
}

void		ft_parse_precision(const char *str, t_flags *flags)
{
	int i;

	i = 1;
	if (str[i] == '*')
		flags->precision = va_arg(flags->ap, int);
	else
		flags->precision = ft_atoi(&str[i]);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_get_displayed_precision(t_flags *flags, long int nbr, int len)
{
	int		count;

	count = flags->precision - len;
	if (nbr < 0 && count >= 0)
	{
		count++;
		flags->width--;
	}
	return (count);
}
