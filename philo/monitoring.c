/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:37:16 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/06 14:22:47 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ate_enough(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->number_of_philo)
	{
		pthread_mutex_lock(&philo[i].meal_mutex);
		if (philo[i].meals_eaten < philo[i].data->number_of_meals)
		{
			pthread_mutex_unlock(&philo[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].meal_mutex);
		i++;
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	long	last;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo[0].data->stop_mutex);
		if (philo[0].data->stop)
		{
			pthread_mutex_unlock(&philo[0].data->stop_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo[0].data->stop_mutex);
		if (philo[0].data->number_of_meals != -1 && ate_enough(philo))
		{
			pthread_mutex_lock(&philo[0].data->stop_mutex);
			philo[0].data->stop = 1;
			pthread_mutex_unlock(&philo[0].data->stop_mutex);
			return (NULL);
		}
		i = 0;
		while (i < philo[0].data->number_of_philo)
		{
			pthread_mutex_lock(&philo[i].meal_mutex);
			last = philo[i].last_meal;
			pthread_mutex_unlock(&philo[i].meal_mutex);

			if (get_time() - last > philo[i].data->time_to_die)
			{
				pthread_mutex_lock(&philo[i].data->print);
				printf("%ld %d died\n",
					get_time() - philo[i].data->start_time,
					philo[i].id);
				pthread_mutex_unlock(&philo[i].data->print);
				pthread_mutex_lock(&philo[i].data->stop_mutex);
				philo[i].data->stop = 1;
				pthread_mutex_unlock(&philo[i].data->stop_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
}
