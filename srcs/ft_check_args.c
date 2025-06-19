/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:29:25 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/19 15:05:24 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if (c >= '\t' && c <= '\f')
		return (1);
	return (0);
}

static int	ft_is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

static int	ft_check_max(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX)
		return (1);
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			while (ft_isspace(av[i][j]))
				j++;
			if (av[i][j] == '-')
				ft_error_exit("⛔ Only positive value ⛔\n");
			if (!ft_is_digit(av[i][j]))
				ft_error_exit("⛔ Only digit ⛔\n");
			j++;
		}
		if (ft_check_max(av[i]))
				ft_error_exit("⛔ INT_MAX is the limited ⛔\n");
		i++;
	}
	return (0);
}
