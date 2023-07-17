/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:05:08 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 15:49:13 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

extern t_node	*ft_stack_create_node(void *data);

void	ft_stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->head = NULL;
}

void	ft_stack_push(t_stack *stack, void *data)
{
	t_node	*new_node;

	stack->size++;
	if (!stack->head)
	{
		stack->head = ft_stack_create_node(data);
		return ;
	}
	new_node = ft_stack_create_node(data);
	new_node->next = stack->head;
	stack->head = new_node;
}

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*removed_node;

	if (!stack->head)
		return (NULL);
	removed_node = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	return (removed_node);
}
