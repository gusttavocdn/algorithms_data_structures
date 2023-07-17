/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:59:19 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 21:07:31 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern t_node	*ft_lst_create_node(void *data);

void	ft_lst_init(t_list *list)
{
	list->size = 0;
	list->head = NULL;
}

void	ft_lst_prepend(t_list *list, void *data)
{
	t_node	*new_head;

	list->size++;
	if (!list->head)
	{
		list->head = ft_lst_create_node(data);
		return ;
	}
	new_head = ft_lst_create_node(data);
	new_head->next = list->head;
	list->head = new_head;
}

void	ft_lst_append(t_list *list, void *data)
{
	t_node	*last_node;
	size_t	counter;

	if (!list->head)
	{
		list->head = ft_lst_create_node(data);
		list->size++;
		return ;
	}
	last_node = list->head;
	counter = 0;
	while (counter < (list->size - 1))
	{
		last_node = last_node->next;
		counter++;
	}
	last_node->next = ft_lst_create_node(data);
	list->size++;
}

void	ft_lst_insert_at(t_list *list, size_t index, void *data)
{
	t_node	*prev_node;
	t_node	*last_node;
	t_node	*new_node;
	size_t	counter;

	if (index == 0 || !list->head)
		return (ft_lst_prepend(list, data));
	last_node = list->head;
	prev_node = NULL;
	counter = 0;
	while (counter < index && counter < list->size)
	{
		prev_node = last_node;
		last_node = last_node->next;
		counter++;
	}
	new_node = ft_lst_create_node(data);
	new_node->next = last_node;
	prev_node->next = new_node;
	list->size++;
}

void	*ft_lst_remove_node(t_list *list, char *data)
{
	t_node	*current_node;
	t_node	*prev_node;

	if (!list->head)
		return (NULL);
	list->size--;
	if (memcmp(list->head->data, data, strlen(data)) == 0)
	{
		list->head = list->head->next;
		return (data);
	}
	current_node = list->head->next;
	prev_node = list->head;
	while (current_node != NULL)
	{
		if (memcmp(current_node->data, data, strlen(data)) == 0)
		{
			prev_node->next = current_node->next;
			ft_lst_del_node(current_node, free);
			return (data);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
	return (NULL);
}
