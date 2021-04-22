/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:01:08 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 15:01:09 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			dst_len;
	size_t			src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = dst_len;
	if (size < dst_len)
		return (src_len + size);
	while (*src && i < (unsigned int)size - 1 && size > 0)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
