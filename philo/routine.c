/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:19:58 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/06 11:48:59 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo, "has taken a fork");
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->stop_mutex);
		if (philo->data->stop)
		{
			pthread_mutex_unlock(&philo->data->stop_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->data->stop_mutex);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

