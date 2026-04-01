/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:22 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/01 16:52:54 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO 

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	int	stop;
	long	start_time;

	pthread_mutex_t *forks;
	pthread_mutex_t print;
}				t_data;

typedef struct s_philo
{
	int id;
	long last_meal;
	int nbr_meals;
	
	pthread_t thread;
	
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	
	t_data *data;
}				t_philo;

/*parsing.c*/
int	parse_args(t_data *data, int argc, char **argv);

/*utils_parsing.c*/
int	ft_atoi(const char *str);
int	verif_number(char *str);
int	check_int(char *str);

/*init.c*/
int	init_forks(t_data *data);
void	init_philos(t_philo *philo, t_data *data);

/*philo.c*/
int	create_threads(t_philo *philo, t_data *data);
void	*routine(void *arg);
void	print_msg(t_philo *philo, char *msg);

/*routine.c*/
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

/*monitoring*/
long	get_time(void);
void	*monitor(void *arg);

#endif