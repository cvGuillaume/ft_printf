/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:55:41 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/26 19:50:52 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\t' || c == ' '
		|| c == '\v' || c == '\n' || c == '\r');
}

int			ft_atoi(char const *str)
{
	unsigned long long	final;
	int					sign;

	final = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		final = final * 10 + *str - '0';
		str++;
	}
	return (sign * final);
}
