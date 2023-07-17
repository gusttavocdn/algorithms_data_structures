/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:00:30 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 23:19:17 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdint.h>
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_list	list;
	t_node	*node;
	size_t	counter;

	// void	*data;
	(void)argc;
	(void)argv;
	ft_lst_init(&list);
	ft_lst_append(&list, strdup("Marcos"));
	ft_lst_append(&list, strdup("Marcos"));
	ft_lst_append(&list, strdup("Gustavo"));
	ft_lst_remove_node(&list, "Gustavo");
	counter = 0;
	node = list.head;
	while (counter < list.size)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
		counter++;
	}
	ft_lst_clear(&list, free);
	printf("%lu", list.size);
	return (EXIT_SUCCESS);
}
