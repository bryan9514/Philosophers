/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:05:42 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/05 18:08:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error_create_thread(t_data *data, int i, char *mgs)
{
	ft_putstr_fd(RED "❌ Error: failed to create ", 2);
	ft_putstr_fd(mgs, 2);
	ft_putstr_fd(" thread.\n" RST, 2);
	while (--i >= 0)
		pthread_join(data->philo[i].thread_id, NULL);
	free_alloc(data->alloctrack);
}

static void	one_philo(t_data *data)
{
	print_status(&data->philo[0], FORK);
	ft_my_usleep(data->time_to_die, data);
	print_status(&data->philo[0], DIED);
	data->end_rutine = true;
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_rutine = get_time();
	while (++i < data->nbr_philos)
	{
		if (data->nbr_philos == 1)
			return (one_philo(data), 0);
		if (pthread_create(&data->philo[i].thread_id, NULL, start_routine,
				&data->philo[i]) != 0)
		{
			error_create_thread(data, i, "philosophers");
			return (1);
		}
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
	{
		error_create_thread(data, i, "monitor");
		return (1);
	}
	return (0);
}
