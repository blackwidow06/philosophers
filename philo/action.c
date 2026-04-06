/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:48:10 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/06 13:46:21 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_msg(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_msg(philo, "is eating");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	usleep(philo->data->time_to_eat * 1000);
}

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	print_msg(philo, "is thinking");
}
