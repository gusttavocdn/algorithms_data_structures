/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:08:12 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 12:12:06 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

extern t_qnode	*ft_queue_create_node(void *data);

void	ft_queue_init(t_queue *queue)
{
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
}

void	ft_queue_enqueue(t_queue *queue, void *data)
{
	t_qnode	*new_node;

	if (queue->size == 0)
	{
		queue->head = ft_queue_create_node(data);
		queue->tail = queue->head;
		queue->size++;
		return ;
	}
	new_node = ft_queue_create_node(data);
	queue->tail->next = new_node;
	queue->tail = new_node;
	queue->size++;
}

t_qnode	*ft_queue_dequeue(t_queue *queue)
{
	t_qnode	*removed_node;

	if (queue->size == 0)
		return (NULL);
	queue->size--;
	removed_node = queue->head;
	queue->head = queue->head->next;
	if (queue->size == 0)
		queue->tail = NULL;
	removed_node->next = NULL;
	return (removed_node);
}

t_qnode	*ft_queue_peek(t_queue *queue)
{
	if (queue->size == 0)
		return (NULL);
	return (queue->head);
}
