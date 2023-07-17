/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_memory_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:44:26 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 12:02:17 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	ft_queue_del_node(t_qnode *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->data);
	free(node);
	node = NULL;
}

void	ft_queue_clear(t_queue *queue, void (*del)(void *))
{
	t_qnode	*current_node;
	t_qnode	*next_node;

	if (queue->size == 0)
		return ;
	current_node = queue->head;
	next_node = current_node->next;
	while (next_node)
	{
		ft_queue_del_node(current_node, del);
		current_node = next_node;
		next_node = next_node->next;
	}
	ft_queue_del_node(current_node, del);
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
}

t_qnode	*ft_queue_create_node(void *data)
{
	t_qnode	*new_node;

	new_node = (t_qnode *)malloc(sizeof(t_qnode));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
