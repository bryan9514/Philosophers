/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:27:06 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/26 19:57:51 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_alloc(t_alloc_mgr *tracker)
{
	t_alloc_list	*tmp;

	while (tracker->head)
	{
		tmp = tracker->head;
		if (tmp->ptr && !tmp->freed)
		{
			free(tmp->ptr);
			tmp->freed = true;
		}
		tracker->head = tmp->next;
		free(tmp);
	}
	tracker->count = 0;
}

void	printf_alloc(t_alloc_mgr *tracker)
{
	t_alloc_list	*tmp;

	printf("\n--- Lista de malloc realizados ---\n");
	tmp = tracker->head;
	while (tmp)
	{
		printf("ID : %-3d		| Direccion: %p 	| Freed: %d	"
				"| Linea: %-4d 	| Archivo: %s\n",
				tmp->id,
				tmp->ptr,
				tmp->freed,
				tmp->line,
				tmp->file);
		tmp = tmp->next;
	}
	printf("--- Fin de la lista ---\n\n");
}

static t_alloc_list	*create_node(void *ptr, t_alloc_mgr *tracker, int line,
		const char *file)
{
	t_alloc_list	*node;

	node = malloc(sizeof(t_alloc_list));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->id = tracker->count + 1;
	node->freed = false;
	node->line = line;
	node->file = file;
	node->next = tracker->head;
	return (node);
}

void	*safe_malloc(size_t bytes, t_alloc_mgr *tracker, int line,
		const char *file)
{
	void			*ptr;
	t_alloc_list	*node;

	ptr = malloc(bytes);
	if (!ptr)
	{
		error_alloc(file, line);
		free_alloc(tracker);
		return (NULL);
	}
	node = create_node(ptr, tracker, line, file);
	if (!node)
	{
		error_alloc(file, line);
		free(ptr);
		free_alloc(tracker);
		return (NULL);
	}
	tracker->head = node;
	tracker->count++;
	return (ptr);
}
