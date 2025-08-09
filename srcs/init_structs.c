/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:18:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/09 12:43:05 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_check(t_data *data, char **av)
{
	if (data->time_to_die < 100 || data->time_to_eat < 100
		|| data->time_to_sleep < 100)
		ft_putstr_fd(YLW
			"\n⚠️  Warning: Values lower than 100ms may cause "
			"synchronization issues. ⚠️\n\n" RST, 1);
	if (av[5])
		data->nbr_limit_meals = ft_atol(av[5]);
	else
		data->nbr_limit_meals = -1;
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->philo[i].meal_mutex, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->philo[i].meal_count_mutex, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->state_death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->state_routine, NULL) != 0)
		return (1);
	return (0);
}

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].counts_meals = 0;
		data->philo[i].full = false;
		data->philo[i].last_meals = get_time();
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
		ft_putstr_fd(YLW "\n⚠️  Warning: The maximum recommended"
			"number is 200.\n\n" RST, 1);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	ft_check(data, av);
	data->start_rutine = 0;
	data->end_rutine = false;
	data->philo = safe_malloc(sizeof(t_philo) * data->nbr_philos,
			data->alloctrack, __LINE__, __FILE__);
	if (!data->philo)
		return (1);
	data->forks = safe_malloc(sizeof(t_mtx) * data->nbr_philos,
			data->alloctrack, __LINE__, __FILE__);
	if (!data->forks)
		return (1);
	memset(data->forks, 0, sizeof(t_mtx) * data->nbr_philos);
	init_philo(data);
	if (init_mutex(data))
		return (1);
	return (0);
}
