/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:41:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/21 10:58:41 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * correct input ./philo 4 800 200 200 [5]
 *                  [0] [1][2] [3] [4] [5]
*/
int	main(int ac, char **av)
{
	t_info_philo	philo;

	if (!(ac == 6 || ac == 5) || ft_check_args(ac, av))
	{
		ft_error_exit(R \
"\t\t\t❌ Incorrect input ❌\n " "The sintaxys is:"RST \
W" ./philo 4 800 200 200"RST R "  or  "RST \
W"./philo 4 800 200 200 5\n"RST);
	}
	init_the_structs(&philo, av);
	return (0);
}
