/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:44:45 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/18 22:32:22 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_sep(int prev, t_list *number)
{
	unsigned int	key;
	t_number_dict	*dict;
	char			*str;

	dict = number->content;
	key = dict->number;
	str = dict->word_en;
	if (prev >= 20 && prev <= 99 && key >= 1 && key <= 9)
		ft_putchar('-');
	else if (((number->next == NULL)
			|| (key >= 20 && key <= 99 && number->next->next == NULL))
		&& (key >= 1 && key <= 99)
		&& (prev == 100 || prev == 1000
			|| prev == 1000000 || prev == 1000000000))
		ft_putstr(" and ");
	else if (key && (prev == 1000 || prev == 1000000 || prev == 1000000000))
		ft_putstr(", ");
	else
		ft_putchar(' ');
}

void	print_zero(t_number_dict *dict)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (dict[i].number == 0)
		{
			ft_putstr(dict[i].word_en);
			return ;
		}
	}
}

void	print_number(t_list *number)
{
	unsigned int	key;
	t_number_dict	*dict;
	char			*str;

	while (number->next != NULL)
	{
		dict = number->content;
		key = dict->number;
		str = dict->word_en;
		ft_putstr(str);
		print_sep(key, number->next);
		number = number->next;
	}
	dict = number->content;
	str = dict->word_en;
	ft_putstr(str);
	ft_putchar('\n');
}
