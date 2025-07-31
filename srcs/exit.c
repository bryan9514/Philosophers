/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:08:04 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/31 11:13:47 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_rutine(t_data *data)
{
	join_pthreads(data);
	destroy_mutexs(data);
	free_alloc(data->alloctrack);
}

void	destroy_mutexs(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].meal_mutex);
		pthread_mutex_destroy(&data->philo[i].meal_count_mutex);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->state_death);
	pthread_mutex_destroy(&data->state_routine);
}

void	join_pthreads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		pthread_join(data->philo[i].thread_id, NULL);
	pthread_join(data->monitor_thread, NULL);
}
