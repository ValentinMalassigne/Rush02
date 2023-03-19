/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:19:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/19 17:07:12 by liguyon          ###   ########.fr       */
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

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

// temporary main for testing
int	main(int ac, char **av)
{
	long	n;
	t_number_dict	*dict;

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
	if (parse(dict, ac, av) == ERROR_DICT)
	{
		free(dict);
		return (print_error(ERROR_DICT));
	}
	free(dict); //temporary
	return (0); //temporary
	if (num_to_text((unsigned int)n, dict) == ERROR_DICT)
		return (print_error(ERROR_DICT));
	return (0);
}
