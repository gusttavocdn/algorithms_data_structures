/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:00:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 15:49:18 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

// Standard Library headers
# include <stdlib.h>
// # include <unistd.h>

// Enum declarations

// Macro declarations

// Struct declarations
typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*head;
}					t_stack;

// Function declarations
void				ft_stack_init(t_stack *stack);
void				ft_stack_push(t_stack *stack, void *data);
t_node				*ft_stack_pop(t_stack *stack);
void				ft_stack_clear(t_stack *stack, void (*del)(void *));
void				ft_stack_del_node(t_node *node, void (*del)(void *));
#endif // STACK_H
