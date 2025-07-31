/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:11:22 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/30 16:15:52 by brturcio         ###   ########.fr       */
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
	// Tomar los dos tenedores
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	// Actualizar el último tiempo de comida protegido por mutex
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meals = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EAT);
	usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->counts_meals++;
	pthread_mutex_unlock(&philo->meal_count_mutex);
	// Soltar los tenedores
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
	usleep(philo->data->time_to_sleep);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!philo->data->end_rutine)
	{
		ft_eat(philo);
		pthread_mutex_lock(&philo->data->state_death);
		if (philo->data->end_rutine)
		{
			pthread_mutex_unlock(&philo->data->state_death);
			break ;
		}
		pthread_mutex_unlock(&philo->data->state_death);
		ft_sleep(philo);
		if (philo->data->end_rutine)
		{
			pthread_mutex_unlock(&philo->data->state_death);
			break ;
		}
		pthread_mutex_unlock(&philo->data->state_death);
		ft_think(philo);
	}
	return (NULL);
}
