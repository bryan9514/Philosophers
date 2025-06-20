/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:44:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/21 10:05:22 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>

# define BR		"\e[0;90m"
# define R		"\e[0;91m"
# define G		"\e[0;92m"
# define Y		"\e[0;93m"
# define B		"\e[0;94m"
# define P		"\e[0;95m"
# define C		"\e[0;96m"
# define W		"\e[0;97m"
# define RST	"\033[0m"

# define FALSE 0
# define TRUE 1

/*
 * struct for input args
 * ./philo 4 800 200 200 [5]
*/
typedef struct	s_info_philo
{
	long	nbr_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	time_simulation_start;
	int		end_simulation;
}	t_info_philo;

//****initialize the structures******/
int	init_the_structs(t_info_philo *philo , char **av);

int	ft_check_args(int ac, char **av);

long	ft_atol(char *str);

/*freeing memory*/
void	free_structs(t_info_philo *philo);
void	ft_error_exit(char *str);

/***ft_utils.c***/

/*for printf the errors*/
void	ft_putstr_fd(char *s, int fd);

#endif
