/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_memory_management.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:44:26 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 21:08:32 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lst_del_node(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->data);
	del(node);
	node = NULL;
}

void	ft_lst_clear(t_list *list, void (*del)(void *))
{
	t_node	*current_node;
	t_node	*next_node;

	if (!list->head)
		return ;
	current_node = list->head;
	next_node = current_node->next;
	while (next_node)
	{
		ft_lst_del_node(current_node, del);
		current_node = next_node;
		next_node = next_node->next;
	}
	ft_lst_del_node(current_node, del);
	list->size = 0;
	list->head = NULL;
}

t_node	*ft_lst_create_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
