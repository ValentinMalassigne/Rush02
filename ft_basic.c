/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:10:10 by llaigle           #+#    #+#             */
/*   Updated: 2023/03/18 14:21:24 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
    while (str[i] < '0' || str[i] > '9')
    {
        i++;
    }
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}