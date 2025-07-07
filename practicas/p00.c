/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:43:15 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/07 15:07:42 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*ft_mi_funcion(void *arg)
{
	int	num;

	num = *(int *)arg;
	printf("This is the pthread\nand the number is : %d\n", num);
	return (NULL);

}

void	*ft_safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	return (ptr);
}

// void	ft_crear_y_ejecutar_threads(int n, void *(*func)(void *), void **args)
// {
// 	int			i;
// 	pthread_t	*threads;

// 	i = 0;
// 	threads = ft_safe_malloc(sizeof(pthread_t) * n);
// 	while (i < n)
// 	{
// 		if (pthread_create(&threads[i], NULL, func, args[i]) != 0)
// 		{
// 			perror("pthread_create");
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		pthread_join(threads[i], NULL);
// 		i++;
// 	}
// 	free(threads);
// }

int	main(int ac, char **av)
{
	(void)ac;
	int			num;
	pthread_t	*hilo;
	int			i;

	i = 0;
	num = atoi(av[1]);
	hilo = ft_safe_malloc(sizeof(pthread_t));
	pthread_create(hilo, NULL, ft_mi_funcion, &num);
	printf("This is the main.\n");
	pthread_join(*hilo, NULL);
	while (i < num)
	{
		free(hilo[i]);
		i++;
	}
	return (0);
}
