/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:07:20 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 12:06:00 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

// Standard Library headers
# include <stdlib.h>
// # include <unistd.h>

// Enum declarations

// Macro declarations

// Struct declarations
typedef struct s_qnode
{
	void			*data;
	struct s_qnode	*next;
}					t_qnode;

typedef struct s_queue
{
	int				size;
	t_qnode			*head;
	t_qnode			*tail;
}					t_queue;

// Function declarations
void				ft_queue_init(t_queue *queue);
void				ft_queue_enqueue(t_queue *queue, void *data);
void				ft_queue_del_node(t_qnode *node, void (*del)(void *));
void				ft_queue_clear(t_queue *queue, void (*del)(void *));
t_qnode				*ft_queue_dequeue(t_queue *queue);
#endif // QUEUE_H
