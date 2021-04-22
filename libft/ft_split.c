/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:59:47 by gcornet-          #+#    #+#             */
/*   Updated: 2020/11/24 14:59:49 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_mat(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

static int	spot_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	compte_mot(const char *str, char charset)
{
	int		counter;
	int		i;
	int		check;

	counter = 0;
	i = 0;
	check = 0;
	while (str[i])
	{
		if (spot_charset(str[i], charset) == 1)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

static char	**sep(char **mat, const char *str, char charset, int len)
{
	int	y;
	int	x;
	int z;

	y = 0;
	z = 0;
	x = 0;
	while (y < compte_mot(str, charset))
	{
		len = 0;
		while (str[z] && spot_charset(str[z], charset) == 1)
			z++;
		while (str[z++] && spot_charset(str[z], charset) == 0)
			len++;
		if (!(mat[y] = (char*)ft_calloc(len + 2, sizeof(char))))
			return (free_mat(mat));
		x = -1;
		while (++x <= len)
			mat[y][x] = str[x + z - len - 1];
		mat[y][x] = '\0';
		y++;
	}
	mat[y] = NULL;
	return (mat);
}

char		**ft_split(char const *s, char c)
{
	char	**mat;
	int		len;

	len = 0;
	if (!(mat = (char**)ft_calloc((compte_mot((char *)s, c) + 1),
			sizeof(char*))))
		return (NULL);
	sep(mat, s, c, len);
	return (mat);
}
