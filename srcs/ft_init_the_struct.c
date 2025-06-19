/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_the_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:18:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/19 14:49:04 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Initialization only of the **info philo structure**
 * There are currently 7 fields.
 * ⚠️ If more fields are added in the future, update this section accordingly.
 * contains the input  ./philo 4 400 200 200
*/
t_info_philo	*init_the_structs(char **av)
{
	t_info_philo	*philo;

	(void)av;
	philo = malloc(sizeof(t_info_philo));
	if (!philo)
		return (NULL);
	philo->nbr_philos = ft_atol(av[1]);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		philo->nbr_limit_meals = ft_atol(av[5]);
	else
		philo->nbr_limit_meals = 0;
	philo->time_simulation_start = 0;
	philo->end_simulation = FALSE;
	return(philo);
}
