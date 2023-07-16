#ifndef LINKED_LIST_H
# define LINKED_LIST_H

// Standard Library headers
//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Related headers
//# include "libft.h"

// Enum declarations

// Macro declarations

// Struct declarations

typedef struct s_node
{
	void			*data;
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
// t_node				*ft_lst_create_node(void *data);

#endif // LINKED_LIST_H
