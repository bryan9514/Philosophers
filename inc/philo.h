/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:44:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/07/30 15:28:47 by brturcio         ###   ########.fr       */
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


# define BLK "\e[0;90m"
# define RED "\e[0;91m"
# define GRN "\e[0;92m"
# define YLW "\e[0;93m"
# define BLU "\e[0;94m"
# define PUR "\e[0;95m"
# define CYN "\e[0;96m"
# define WHT "\e[0;97m"
# define RST "\e[0m"


# define FORK PUR"has taken a fork"RST
# define EAT GRN"is eating"RST
# define SLEEP CYN"is sleeping"RST
# define THINK YLW"is thinking"RST
# define DIED RED"died"RST

# define SAFE_MALLOC(bytes, tracker) safe_malloc(bytes, tracker, __LINE__, __FILE__)

typedef pthread_mutex_t t_mtx;

typedef struct s_alloc_list
{
	void				*ptr;
	int					id;
	int					freed;
	int					line;
	const char			*file;
	struct s_alloc_list	*next;
}	t_alloc_list;

typedef struct s_alloc_mgr
{
	t_alloc_list	*head;
	int				count;
} t_alloc_mgr;

typedef struct s_philo
{
	int				id;
	long			counts_meals;
	bool			full;
	long			last_meals;
	t_mtx			*left_fork;
	t_mtx			*right_fork;
	t_mtx			meal_mutex;
	t_mtx			meal_count_mutex;
	struct s_data	*data;
	pthread_t		thread_id;
}	t_philo;

typedef struct	s_data
{
	long		nbr_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_rutine;
	bool		end_rutine;
	t_philo		*philo;
	t_mtx		*forks;
	t_mtx		print;
	t_mtx		state_death;
	t_alloc_mgr	*alloctrack;
	pthread_t	monitor_thread;
}	t_data;

/*
=============================================================
                 control_alloc.c
=============================================================
*/
void	*safe_malloc(size_t bytes, t_alloc_mgr *tracker, int line, const char *file);
void	free_alloc(t_alloc_mgr *tracker);
void	printf_alloc(t_alloc_mgr *tracker);

/*
=============================================================
                 errors.c
=============================================================
*/
void	error_alloc(const char *file, int line);
void	error_exit(char *str);
void	ft_putstr_fd(char *s, int fd);

/*
=============================================================
                 init_the_struct.c
=============================================================
*/
int		init_data(t_data *data, char **av);

/*
=============================================================
                 parsin_args.c
=============================================================
*/
long	ft_atol(char *str);
int		parse_args(int ac, char **av);

/*
=============================================================
                 play_simulation.c
=============================================================
*/
// void	*play_rutine(void *arg);
int		init_threads(t_data *data);


/*
=============================================================
                 utils.c
=============================================================
*/
long	get_time(void);



void	join_pthreads(t_data *data);
void	destroy_mutexs(t_data *data);
void	end_rutine(t_data *data);

void	print_status(t_philo *philo, char *action);

void	*start_routine(void *arg);


void	*monitor_routine(void *arg);

#endif
