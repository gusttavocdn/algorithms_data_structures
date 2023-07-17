/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_memory_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:10:00 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 15:44:16 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_del_node(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->data);
	free(node);
	node = NULL;
}

void	ft_stack_clear(t_stack *stack, void (*del)(void *))
{
	t_node	*current_node;
	t_node	*next_node;

	if (stack->size == 0)
		return ;
	current_node = stack->head;
	next_node = current_node->next;
	while (next_node)
	{
		ft_stack_del_node(current_node, del);
		current_node = next_node;
		next_node = next_node->next;
	}
	ft_stack_del_node(current_node, del);
	stack->size = 0;
	stack->head = NULL;
}

t_node	*ft_stack_create_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
