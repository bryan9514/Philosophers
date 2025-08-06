/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:41:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/06 15:31:13 by brturcio         ###   ########.fr       */
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
			return (1);
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
	if (check_empty_value(av))
		error_exit("⛔ empty value ⛔\n");
	if (!(ac == 6 || ac == 5) || parse_args(ac, av))
	{
		error_exit(RED "\t\t\t❌ Incorrect input ❌\n "
			"The sintaxys is:"RST WHT " ./philo 4 800 200 200"RST
			RED "  or  "RST WHT "./philo 4 800 200 200 5\n"RST);
	}
	if (init_data(&philo, av))
		return (1);
	if (init_threads(&philo))
		return (1);
	end_rutine(&philo);
	return (EXIT_SUCCESS);
}
