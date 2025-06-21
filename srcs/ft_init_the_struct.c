/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_the_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:18:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/21 10:50:00 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Initialization only of the **info philo structure**
 * There are currently 7 fields.
 * ⚠️ If more fields are added in the future, update this section accordingly.
 * contains the input  ./philo 4 400 200 200
*/
int	init_the_structs(t_info_philo *philo, char **av)
{
	philo->nbr_philos = ft_atol(av[1]);
	philo->time_to_die = ft_atol(av[2]) * 1000;
	philo->time_to_eat = ft_atol(av[3]) * 1000;
	philo->time_to_sleep = ft_atol(av[4]) * 1000;
	if (philo->time_to_die < 100000 || philo->time_to_eat < 100000 \
|| philo->time_to_sleep < 100000)
		ft_error_exit(Y \
"⚠️  Warning: values lower than 100ms may cause " \
"synchronization issues. ⚠️\n" RST);
	if (av[5])
		philo->nbr_limit_meals = ft_atol(av[5]) * 1000;
	else
		philo->nbr_limit_meals = -1;
	philo->time_simulation_start = 0;
	philo->end_simulation = FALSE;
	return (0);
}
