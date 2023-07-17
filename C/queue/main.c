/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:08:50 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 12:08:10 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	test(void *s)
{
	printf("Deleting => %s\n", (char *)s);
	return ;
}

int	main(int argc, char const *argv[])
{
	t_queue	queue;
	t_qnode	*node;

	// t_qnode	*removed_node;
	(void)argv;
	(void)argc;
	ft_queue_init(&queue);
	ft_queue_enqueue(&queue, "Gustavo");
	ft_queue_enqueue(&queue, "Larissa");
	ft_queue_enqueue(&queue, "Nicolly");
	ft_queue_enqueue(&queue, "Marcos");
	ft_queue_enqueue(&queue, "Luciene");
	// ft_queue_dequeue(&queue);
	node = queue.head;
	for (int i = 0; i < queue.size; i++)
	{
		printf("Value => %s\n", (char *)node->data);
		node = node->next;
	}
	printf("Queue Size => %d\n", queue.size);
	ft_queue_clear(&queue, test);
	return (0);
}
