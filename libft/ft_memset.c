/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:57:40 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 14:57:41 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	size_t			i;

	b2 = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		b2[i] = c;
		len--;
		i++;
	}
	return (b);
}
