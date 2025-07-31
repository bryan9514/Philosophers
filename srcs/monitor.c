/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:55:28 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/30 16:16:33 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_data *data)
{
	long	time_not_eat;
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->state_death);
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		time_not_eat = get_time() - data->philo[i].last_meals;
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		if (time_not_eat > data->time_to_die)
		{
			data->end_rutine = true;
			print_status(&data->philo[i], DIED);
			pthread_mutex_unlock(&data->state_death);
			return (1);
		}
		pthread_mutex_unlock(&data->state_death);
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
		if (data->philo[i].counts_meals >= data->nbr_limit_meals)
			count_meals++;
		pthread_mutex_unlock(&data->philo[i].meal_count_mutex);
		i++;
	}
	if (count_meals == data->nbr_philos)
	{
		data->end_rutine = true;
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->end_rutine)
	{
		if (check_dead(data))
			return (NULL);
		if (check_meals(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

