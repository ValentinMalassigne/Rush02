/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:28:04 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/19 13:44:50 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define ERROR_ARG 101
# define ERROR_DICT 102

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_number_dict
{
	unsigned int	number;
	char			*word_en;
}	t_number_dict;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long	ft_atol(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
t_list	*ft_lstnew(void *content);
void	print_number(t_list *number);
void	print_zero(t_number_dict *dict);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		num_to_text(unsigned int n, t_number_dict *dict);
int		ft_strlen(char *str);

#endif
