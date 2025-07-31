/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:11:22 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/31 13:04:50 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_rutine, philo->id,
		action);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_eat(t_philo *philo)
{
	t_mtx	*first;
	t_mtx	*second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(first);
	print_status(philo, FORK);
	pthread_mutex_lock(second);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meals = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EAT);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->counts_meals++;
	pthread_mutex_unlock(&philo->meal_count_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_think(t_philo *philo)
{
	print_status(philo, THINK);
}

void	ft_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(500 , philo->data);
	while (!philo->data->end_rutine)
	{
		ft_eat(philo);
		pthread_mutex_lock(&philo->data->state_routine);
		if (philo->data->end_rutine)
		{
			pthread_mutex_unlock(&philo->data->state_routine);
			break ;
		}
		pthread_mutex_unlock(&philo->data->state_routine);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->data->state_routine);
		if (philo->data->end_rutine)
		{
			pthread_mutex_unlock(&philo->data->state_routine);
			break ;
		}
		pthread_mutex_unlock(&philo->data->state_routine);
		ft_think(philo);
	}
	return (NULL);
}
