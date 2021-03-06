/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:21:57 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/20 19:28:13 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_count(const char *str, char c)
{
	int count;

	count = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static int		f_chcount(const char *str, char c, int i)
{
	int count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char		**frees(char const **s, int i)
{
	while (i > 0)
	{
		i--;
		free((void*)s[i]);
	}
	free(s);
	return ((char **)NULL);
}

static char		**ft_r(char const *s, char **s2, char c, int m)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < m)
	{
		k = 0;
		while (s[i] == c)
			i++;
		s2[j] = (char*)malloc(sizeof(char) * f_chcount(s, c, i) + 1);
		if (!s2[j])
			return (frees((char const**)s2, j));
		while (s[i] && s[i] != c)
			s2[j][k++] = s[i++];
		s2[j][k] = '\0';
		j++;
	}
	s2[j] = 0;
	return (s2);
}

char			**ft_split(char const *s, char c)
{
	char	**s2;

	if (!s)
		return (0);
	if (!(s2 = (char**)malloc(sizeof(char*) * (f_count(s, c) + 1))))
		return (NULL);
	return (ft_r(s, s2, c, f_count(s, c)));
}
