/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:34:17 by pcorina           #+#    #+#             */
/*   Updated: 2021/10/20 20:43:06 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	line_fill(char *str, long *n, int *count)
{
	*str = *n % 10 + 48;
	*n /= 10 ;
	*count -= 1;
}

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*str;
	long	l;

	l = n;
	count = digit_len(l);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return ((void *)0);
	i = 0;
	if (l < 0)
	{
		l *= -1;
		str[i] = '-';
		i++;
	}
	str[count] = '\0';
	count--;
	while (i <= count)
		line_fill(&str[count], &l, &count);
	return (str);
}
