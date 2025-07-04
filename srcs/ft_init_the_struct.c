/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_the_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:18:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/01 10:13:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_struct_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	philo->id = 0;
	philo->counts_meals = 0;
	philo->full = false;
	philo->last_meals = 0;
	philo->right_fork = ft_safe_malloc(philo->right_fork);
	philo->left_fork = ft_safe_malloc(philo->left_fork);
}

/*
 * Initialization only of the **info philo structure**
 * There are currently 7 fields.
 * ⚠️ If more fields are added in the future, update this section accordingly.
 * contains the input  ./philo 4 400 200 200
*/
int	ft_init_the_structs(t_data *data, char **av)
{
	data->nbr_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	if (data->time_to_die < 100000 || data->time_to_eat < 100000 \
|| data->time_to_sleep < 100000)
		ft_error_exit(Y \
"⚠️  Warning: values lower than 100ms may cause " \
"synchronization issues. ⚠️\n" RST);
	if (av[5])
		data->nbr_limit_meals = ft_atol(av[5]) * 1000;
	else
		data->nbr_limit_meals = -1;
	data->time_simulation_start = 0;
	data->end_simulation = false;
	data->philo = ft_safe_malloc(data->philo);
	data->forks = ft_safe_malloc(data->forks);
	ft_init_struct_philo(data);
	return (0);
}
