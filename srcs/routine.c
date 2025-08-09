/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:11:22 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/09 14:35:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, int action)
{
	if (action != DIED && action != FULL && is_simulation_ended(philo->data))
		return ;
	if ((action == FORK || action == EAT || action == SLEEP || action == THINK)
		&& philo_is_full(philo))
		return ;
	pthread_mutex_lock(&philo->data->print);
	if (action == DIED || action == FULL || !is_simulation_ended(philo->data))
		printf("%ld %d %s\n", get_time() - philo->data->start_rutine,
			philo->id, select_action(action));
	pthread_mutex_unlock(&philo->data->print);
}

static int	ft_eat_continue(t_philo *philo, t_mtx *first, t_mtx *second)
{
	bool	tmp;

	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meals = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EAT);
	tmp = ft_my_usleep(philo->data->time_to_eat, philo->data);
	if (tmp)
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->counts_meals++;
	if (philo->data->nbr_limit_meals != -1
		&& philo->counts_meals == philo->data->nbr_limit_meals)
		philo->full = true;
	pthread_mutex_unlock(&philo->meal_count_mutex);
	return (0);
}

static void	ft_eat(t_philo *philo)
{
	t_mtx	*first;
	t_mtx	*second;

	if (philo_is_full(philo))
		return ;
	if (philo->id % 2 != 0)
	{
		ft_my_usleep(5, philo->data);
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_lock(first);
	print_status(philo, FORK);
	pthread_mutex_lock(second);
	print_status(philo, FORK);
	if (ft_eat_continue(philo, first, second))
		return ;
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (!is_simulation_ended(philo->data))
	{
		if (philo_is_full(philo))
			break ;
		ft_eat(philo);
		if (is_simulation_ended(philo->data) || philo_is_full(philo))
			break ;
		print_status(philo, SLEEP);
		ft_my_usleep(philo->data->time_to_sleep, philo->data);
		if (is_simulation_ended(philo->data) || philo_is_full(philo))
			break ;
		print_status(philo, THINK);
	}
	return (NULL);
}
