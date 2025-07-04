/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:16:06 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/01 10:02:27 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && fd >= 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	*ft_safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = NULL//malloc(bytes);
	if (!ptr)
		ft_error_exit(R "⛔🚨 Error malloc 🚨⛔" RST);
	return (ptr);
}
