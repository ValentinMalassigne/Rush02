/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:19:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/19 15:11:51 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_error(int error)
{
	if (error == ERROR_ARG)
		ft_putstr("Error\n");
	else if (error == ERROR_DICT)
		ft_putstr("Dict Error\n");
	return (0);
}

int	num_is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

// temporary main for testing
int	main(int ac, char **av)
{
	long	n;
	t_number_dict	*dict = {
		{100, "hundred"},
		{1000, "thousand"},
		{1000000, "million"},
		{1000000000, "billion"},
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"},
		{10, "ten"},
		{11, "eleven"},
		{12, "twelve"},
		{13, "thirteen"},
		{14, "fourteen"},
		{15, "fifteen"},
		{16, "sixteen"},
		{17, "seventeen"},
		{18, "eighteen"},
		{19, "nineteen"},
		{20, "twenty"},
		{30, "thirty"},
		{40, "fourty"},
		{50, "fifty"},
		{60, "sixty"},
		{70, "seventy"},
		{80, "eighty"},
		{90, "ninety"},
		{0, "zero"},
		};

	if (ac < 2 || ac > 3)
		return (print_error(ERROR_ARG));
	if (!num_is_valid(av[1]))
		return (print_error(ERROR_ARG));
	n = ft_atol(av[1]);
	if (n == -1)
		return (print_error(ERROR_ARG));
	dict = malloc(sizeof(t_number_dict) * DICT_SIZE);
	if (!dict)
		return (0);
	if (parse(*dict, ac, av) == ERROR_DICT)
		return (print_error(ERROR_DICT));
	if (num_to_text((unsigned int)n, dict) == ERROR_DICT)
		return (print_error(ERROR_DICT));
	return (0);
}
