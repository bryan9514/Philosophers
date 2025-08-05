/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:41:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/08/05 18:26:55 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_alloc_mgr	tracker;
	t_data		philo;

	tracker = (t_alloc_mgr){0};
	philo.alloctrack = &tracker;
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
	// printf_alloc(&tracker);
	end_rutine(&philo);
	return (EXIT_SUCCESS);
}
