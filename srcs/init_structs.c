/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:18:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/30 15:52:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_check(t_data *data, char **av)
{
	if (data->time_to_die < 100000 || data->time_to_eat < 100000
		|| data->time_to_sleep < 100000)
		error_exit(YLW
			"⚠️  Warning: values lower than 100ms may cause "
			"synchronization issues. ⚠️\n" RST);
	if (av[5])
		data->nbr_limit_meals = ft_atol(av[5]);
	else
		data->nbr_limit_meals = -1;
}

static void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philo[i].meal_mutex, NULL);
		pthread_mutex_init(&data->philo[i].meal_count_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->state_death, NULL);
}

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->philo[i].id = i + 1;
		pthread_mutex_lock(&data->philo[i].meal_count_mutex);
		data->philo[i].counts_meals = 0;
		pthread_mutex_unlock(&data->philo[i].meal_count_mutex);
		data->philo[i].full = false;
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		data->philo[i].last_meals = get_time();
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nbr_philos];
		data->philo[i].data = data;
		data->philo[i].thread_id = 0;
		i++;
	}
}

int	init_data(t_data *data, char **av)
{
	data->nbr_philos = ft_atol(av[1]);
	if (data->nbr_philos > 200)
		error_exit(YLW "⚠️  The maximum number of philosophers is 200.\n" RST);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	ft_check(data, av);
	data->start_rutine = 0;
	data->end_rutine = false;
	data->philo = SAFE_MALLOC(sizeof(t_philo) * data->nbr_philos,
			data->alloctrack);
	if (!data->philo)
		return (1);
	data->forks = SAFE_MALLOC(sizeof(t_mtx) * data->nbr_philos,
			data->alloctrack);
	if (!data->forks)
		return (1);
	memset(data->forks, 0, sizeof(t_mtx) * data->nbr_philos);
	init_philo(data);
	init_mutex(data);
	return (0);
}
