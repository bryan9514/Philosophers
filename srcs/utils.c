/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:29:39 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/05 16:39:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_my_usleep(size_t ms, t_data *data)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if (is_simulation_ended(data))
			return (1);
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

char	*select_action(int action)
{
	if (action == FORK)
		return (PUR"has taken a fork"RST);
	if (action == EAT)
		return (GRN"is eating"RST);
	if (action == SLEEP)
		return (CYN"is sleeping"RST);
	if (action == THINK)
		return (YLW"is thinking"RST);
	if (action == DIED)
		return (RED"died"RST);
	if (action == FULL)
		return (BLU"All the philosophers have eaten\n"RST);
	return ("");
}
