/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:37:16 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/03 10:50:56 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo[0].data->stop_mutex);
		if (philo[0].data->stop)
		{
			pthread_mutex_unlock(&philo[0].data->stop_mutex);
			break;
		}
		pthread_mutex_unlock(&philo[0].data->stop_mutex);
		i = 0;
		while (i < philo[0].data->number_of_philo)
		{
			pthread_mutex_lock(&philo[i].meal_mutex);
			if (get_time() - philo[i].last_meal > philo[i].data->time_to_die)
			{
				pthread_mutex_unlock(&philo[i].meal_mutex);
				pthread_mutex_lock(&philo[i].data->print);
				printf("%ld %d died\n",
					get_time() - philo[i].data->start_time, philo[i].id);
				pthread_mutex_unlock(&philo[i].data->print);
				pthread_mutex_lock(&philo[i].data->stop_mutex);
				philo[i].data->stop = 1;
				pthread_mutex_unlock(&philo[i].data->stop_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].meal_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
