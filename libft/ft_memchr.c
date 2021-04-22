/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:57:05 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 14:57:08 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char a;

	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*ptr == a)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
