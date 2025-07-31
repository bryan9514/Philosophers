/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:29:39 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/31 13:02:46 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_usleep(size_t ms)
// {
// 	size_t	start;

// 	start = get_time();
// 	while ((get_time() - start) < ms)
// 		usleep(100);
// 	return (0);
// }

int	ft_usleep(size_t ms, t_data *data)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		pthread_mutex_lock(&data->state_routine);
		if (data->end_rutine)
		{
			pthread_mutex_unlock(&data->state_routine);
			break ;
		}
		pthread_mutex_unlock(&data->state_routine);
		usleep(100);
	}
	return (0);
}


long	get_time(void)
{
	long			start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (start);
}
