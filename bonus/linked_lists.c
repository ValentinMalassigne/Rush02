/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:02:46 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/18 22:27:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (lst && temp)
	{	
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else if (lst)
		*lst = new;
}
