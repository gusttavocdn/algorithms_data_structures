/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:44:28 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 15:50:29 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack	stack;
	t_node	*node;

	ft_stack_init(&stack);
	ft_stack_push(&stack, "Gustavo");
	ft_stack_push(&stack, "Larissa");
	ft_stack_push(&stack, "Nicolly");
	ft_stack_push(&stack, "Marcos");
	ft_stack_pop(&stack);
	ft_stack_pop(&stack);
	node = stack.head;
	for (int i = 0; i < stack.size; i++)
	{
		printf("Data => %s\n", (char *)node->data);
		node = node->next;
	}
	return (0);
}
