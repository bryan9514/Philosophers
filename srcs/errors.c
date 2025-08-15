/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:20:56 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/12 10:18:55 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	error_alloc(const char *file, int line)
{
	ft_putstr_fd("⛔🚨 Malloc failed in ", 2);
	ft_putstr_fd((char *)file, 2);
	ft_putstr_fd(" : ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" 🚨⛔\n", 2);
}

int	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

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
