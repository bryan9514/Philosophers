/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:41:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/12 12:03:19 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_empty_value(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (error_exit("\t\t\t   ⛔ empty value ⛔\n"));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_alloc_mgr	tracker;
	t_data		philo;

	tracker = (t_alloc_mgr){0};
	philo.alloctrack = &tracker;
	if (!(ac == 6 || ac == 5) || check_empty_value(av) || parse_args(ac, av))
	{
		error_exit(RED "\t\t\t❌ Incorrect input ❌\n "
			"The sintaxys is:" RST WHT " ./philo 4 800 200 200" RST
			RED "  or  " RST WHT "./philo 4 800 200 200 5\n" RST);
		return (EXIT_FAILURE);
	}
	if (init_data(&philo, av) || init_threads(&philo))
	{
		end_rutine(&philo);
		return (1);
	}
	end_rutine(&philo);
	return (EXIT_SUCCESS);
}
