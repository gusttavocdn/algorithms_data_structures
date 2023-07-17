/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:08:44 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 21:10:30 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

// Standard Library headers
//# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Related headers
//# include "libft.h"

// Enum declarations

// Macro declarations

// Struct declarations

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	size_t			size;
	t_node			*head;
}					t_list;

// Function declarations

void				ft_lst_init(t_list *list);
void				ft_lst_prepend(t_list *list, void *data);
void				ft_lst_insert_at(t_list *list, size_t index, void *data);
void				ft_lst_append(t_list *list, void *data);
void				*ft_lst_remove_node(t_list *list, char *data);
void				ft_lst_del_node(t_node *node, void (*del)(void *));
void				ft_lst_clear(t_list *list, void (*del)(void *));

#endif // LINKED_LIST_H
