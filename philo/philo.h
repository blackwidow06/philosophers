/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:22 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/07 14:08:12 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				stop;
	long			start_time;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_mutex;
}				t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals_eaten;

	pthread_t		thread;

	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	t_data			*data;
}				t_philo;

/*init.c*/
int		init_forks(t_data *data);
void	init_philos(t_philo *philo, t_data *data);

/*parsing.c*/
int		parse_args(t_data *data, int argc, char **argv);
int		verif_number(char *str);
int		check_int(char *str);
int		ft_error(void);

/*routine*/
void	*routine(void *arg);

/*action.c*/
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

/*monitoring.c*/
void	*monitor(void *arg);

/*utils.c*/
int		ft_atoi(const char *str);
void	print_msg(t_philo *philo, char *msg);
long	get_time(void);
void	free_all(t_data *data, t_philo *philo);

/*eat_utils*/
void	take_forks(t_philo *philo);
int		release_forks(t_philo *philo);
void	eat_and_release(t_philo *philo);

#endif