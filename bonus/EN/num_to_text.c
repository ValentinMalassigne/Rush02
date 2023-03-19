/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:02:51 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/18 22:33:04 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_number(unsigned int n, t_number_dict *dict, t_list **number)
{
	int		i;
	t_list	*new;

	i = -1;
	while (++i < 32)
	{
		if (dict[i].number == n)
		{
			new = ft_lstnew(&dict[i]);
			ft_lstadd_back(number, new);
			return (0);
		}
	}
	return (1);
}

int	convert_number_2(unsigned int n, t_number_dict *dict, t_list **number)
{
	if (n >= 20)
	{
		if (get_number(n - n % 10, dict, number))
			return (1);
		if (n % 10)
		{
			if (get_number(n % 10, dict, number))
				return (1);
		}
	}
	else if (n >= 10 && n <= 19)
	{
		if (get_number(n, dict, number))
			return (1);
	}
	else if (n >= 1 && n <= 9)
	{
		if (get_number(n, dict, number))
			return (1);
	}
	return (0);
}

int	convert_number_1(unsigned int n, t_number_dict *dict, t_list **number)
{
	if (n >= 100)
	{
		convert_number_1(n / 100, dict, number);
		if (get_number(100, dict, number))
			return (1);
		n %= 100;
	}
	if (convert_number_2(n, dict, number))
		return (1);
	return (0);
}

int	convert_number(unsigned int n, t_number_dict *dict, t_list **number)
{
	if (n >= 1000000000)
	{
		convert_number(n / 1000000000, dict, number);
		if (get_number(1000000000, dict, number))
			return (1);
		n %= 1000000000;
	}
	if (n >= 1000000)
	{
		convert_number(n / 1000000, dict, number);
		if (get_number(1000000, dict, number))
			return (1);
		n %= 1000000;
	}
	if (n >= 1000)
	{
		convert_number(n / 1000, dict, number);
		if (get_number(1000, dict, number))
			return (1);
		n %= 1000;
	}
	if (convert_number_1(n, dict, number))
		return (1);
	return (0);
}

int	num_to_text(unsigned int n, t_number_dict *dict)
{
	t_list	*head;
	t_list	*copy;

	if (n == 0)
	{
		print_zero(dict);
		return (0);
	}
	head = NULL;
	if (convert_number(n, dict, &head))
		return (ERROR_DICT);
	print_number(head);
	copy = head;
	while (copy->next != NULL)
	{
		copy = head->next;
		free(head);
		head = copy;
	}
	free(copy);
	return (0);
}
