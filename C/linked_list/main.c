/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:00:30 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/16 17:45:59 by gusda-si         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	ft_lst_init(&list);
	ft_lst_append(&list, (void *)1);
	ft_lst_append(&list, (void *)2);
	ft_lst_append(&list, (void *)3);
	ft_lst_append(&list, (void *)4);
	ft_lst_append(&list, (void *)5);
	ft_lst_append(&list, (void *)6);
	ft_lst_append(&list, (void *)7);
	ft_lst_append(&list, (void *)8);
	ft_lst_append(&list, (void *)9);
	ft_lst_append(&list, (void *)-100);
	// ft_lst_prepend(&list, "Nicolly");
	// ft_lst_insert_at(&list, 2, "Marcos");
	// ft_lst_insert_at(&list, 19, "Luciene");
	counter = 0;
	node = list.head;
	while (counter < list.size)
	{
		printf("%ld\n", (uint64_t)node->data);
		node = node->next;
		counter++;
	}
	printf("%lu", list.size);
	return (EXIT_SUCCESS);
}
