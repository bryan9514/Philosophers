/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:38:01 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/03 21:13:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct s_hilos
{
	int			cont;
	pthread_t	hilo;

}	t_hilos;

void	*mi_funcion(void *arg)
{
	t_hilos	cont;

	cont = *(t_hilos *)arg;
	cont++;
	printf("Soy el hilo y el contador es : %d\n", cont);
	return (NULL);
}

int	main(void)
{
	int		i;
	t_hilos	hilo[5];

	i = 0;
	while (i <= 4)
	{
		if (pthread_create(&hilo[i], NULL, mi_funcion, &hilo->cont) != 0)
		{
			perror("Hilo no creado.\n");
			return (1);
		}
		i++;
	}
	printf("Esto es el main\n");
	i = 0;
	while (i <= 4)
	{
		pthread_join(hilo[i], NULL);
		i++;
	}
	printf("Hilo finalizado.\n");
	return (0);
}
