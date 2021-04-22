/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:57:25 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 14:57:27 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst2;
	unsigned char *src2;

	if (src == dst || !n)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
