/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:00:47 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 15:00:49 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
