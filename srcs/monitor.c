/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:55:28 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/18 16:19:22 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead(t_data *data)
{
	long	time_not_eat;
	int		i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		time_not_eat = get_time() - data->philo[i].last_meals;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		if (time_not_eat > data->time_to_die)
		{
			pthread_mutex_lock(&data->state_routine);
			data->end_rutine = true;
			pthread_mutex_unlock(&data->state_routine);
			print_status(&data->philo[i], DIED);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meals(t_data *data)
{
	int	i;
	int	count_meals;

	count_meals = 0;
	i = 0;
	if (data->nbr_limit_meals == -1)
		return (0);
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->philo[i].meal_count_mutex);
		if (data->philo[i].full)
			count_meals++;
		pthread_mutex_unlock(&data->philo[i].meal_count_mutex);
		i++;
	}
	if (count_meals == data->nbr_philos)
	{
		pthread_mutex_lock(&data->state_routine);
		data->end_rutine = true;
		pthread_mutex_unlock(&data->state_routine);
		print_status(&data->philo[0], FULL);
		return (1);
	}
	return (0);
}

bool	is_simulation_ended(t_data *data)
{
	bool	end;

	pthread_mutex_lock(&data->state_routine);
	end = data->end_rutine;
	pthread_mutex_unlock(&data->state_routine);
	return (end);
}

bool	philo_is_full(t_philo *philo)
{
	bool	full;

	pthread_mutex_lock(&philo->meal_count_mutex);
	full = philo->full;
	pthread_mutex_unlock(&philo->meal_count_mutex);
	return (full);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!is_simulation_ended(data))
	{
		if (check_dead(data))
			return (NULL);
		if (check_meals(data))
			return (NULL);
		ft_my_usleep(3, data);
	}
	return (NULL);
}
