/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:02:50 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 15:02:52 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spot_set(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		z;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	z = 0;
	while (spot_set(s1[i], set) && s1[i])
		i++;
	while (spot_set(s1[j - 1], set) && j > i)
		j--;
	if (!(str = ft_calloc((j - i + 1), sizeof(*s1))))
		return (NULL);
	while (i < j)
		str[z++] = s1[i++];
	str[z] = '\0';
	return (str);
}
