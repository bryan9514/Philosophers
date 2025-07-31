/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:29:39 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/26 22:54:09 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	long			start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (start);
}
