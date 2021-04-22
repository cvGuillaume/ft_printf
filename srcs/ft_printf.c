/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:50:38 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:50:47 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->padding = '\0';
	flags->type = '\0';
	ft_strlcpy(flags->null, "(null)", 7);
	ft_strlcpy(flags->base, "0123456789abcdef", 17);
	flags->ret = 0;
	flags->width = 0;
	flags->precision = -1;
	return (flags);
}

void		ft_treat_args(t_flags *flags)
{
	if (flags->type == 'c')
		ft_print_c(flags);
	if (flags->type == 'd' || flags->type == 'i')
		ft_print_d_i(flags);
	if (flags->type == 'u')
		ft_print_u(flags);
	if (flags->type == 's')
		ft_print_s(flags);
	if (flags->type == 'x' || flags->type == 'X')
		ft_print_x(flags);
	if (flags->type == 'p')
		ft_print_p(flags);
	if (flags->type == '%')
		ft_print_pct(flags);
}

int			ft_parse_flags(const char *str, t_flags *flags, int *j)
{
	if (str[*j + 1])
		*j = *j + 1;
	ft_parse_padding(&str[*j], flags);
	while (str[*j] == '0' || str[*j] == '-')
		*j = *j + 1;
	if (str[*j] == '*')
	{
		flags->width = va_arg(flags->ap, int);
		if (flags->width < 0)
			flags->padding = ' ';
		if (flags->width < 0)
			flags->width = flags->width * (-1);
		*j = *j + 1;
	}
	else if (ft_isdigit(str[*j]))
		flags->width = ft_atoi(&str[*j]);
	while (ft_isdigit(str[*j]))
		*j = *j + 1;
	if (str[*j] == '.')
		ft_parse_precision(&str[*j], flags);
	while (str[*j] == '.' || str[*j] == '*' || ft_isdigit(str[*j]) ||
			str[*j] == '-')
		*j = *j + 1;
	flags->type = str[*j];
	return (check_type(flags));
}

int			ft_printf(const char *str, ...)
{
	t_flags *flags;
	int		i;

	i = 0;
	flags = init_flags();
	if (flags == NULL)
		return (-1);
	va_start(flags->ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_parse_flags(str, flags, &i))
				return (-1);
			ft_treat_args(flags);
			reinit_flags(flags);
		}
		else
			flags->ret += ft_putchar(str[i]);
		i++;
	}
	va_end(flags->ap);
	i = flags->ret;
	free(flags);
	return (i);
}
