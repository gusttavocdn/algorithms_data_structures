/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:59:19 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 19:33:48 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static t_node	*lst_create_node(void *data);

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
		list->head = lst_create_node(data);
		return ;
	}
	new_head = lst_create_node(data);
	new_head->next = list->head;
	list->head = new_head;
}

void	ft_lst_append(t_list *list, void *data)
{
	t_node	*current_node;
	size_t	counter;

	// t_node	*new_tail;
	if (!list->head)
	{
		list->head = lst_create_node(data);
		list->size++;
		return ;
	}
	current_node = list->head;
	counter = 0;
	while (counter < (list->size - 1))
	{
		current_node = current_node->next;
		counter++;
	}
	current_node->next = lst_create_node(data);
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
	new_node = lst_create_node(data);
	new_node->next = last_node;
	prev_node->next = new_node;
	list->size++;
}

static t_node	*lst_create_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
