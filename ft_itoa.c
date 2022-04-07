/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:36:46 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/20 19:25:27 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	while (n)
	{
		if (n < 0)
		{
			n = n * -1;
			count++;
		}
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		i;
	int		negative;

	count = ft_count(n) + 1;
	i = n;
	negative = 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	if (n == 0)
		str[count - 2] = '0';
	str[count - 1] = '\0';
	if (n < 0)
	{
		negative = -1;
		str[0] = '-';
	}
	while (count-- && n)
	{
		i = n % 10 * negative;
		n = n / 10;
		str[count - 1] = i + '0';
	}
	return (str);
}
