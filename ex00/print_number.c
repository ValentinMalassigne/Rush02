/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:44:45 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/18 22:41:26 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
		ft_putchar(' ');
		number = number->next;
	}
	dict = number->content;
	str = dict->word_en;
	ft_putstr(str);
	ft_putchar('\n');
}
