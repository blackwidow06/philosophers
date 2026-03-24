/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:19:58 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/24 15:47:42 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	ft_eat(t_philo *philo)
//{
//	pthread_mutex_lock(philo->left_fork); /*verrouiller la fork*/
//	printf("Philo %d has taken a fork\n", philo->id);

//	pthread_mutex_lock(philo->right_fork);
//	printf("Philo %d has taken a fork\n", philo->id);

//	printf("Philo %d is eating\n", philo->id);
//	usleep(philo->data->time_to_eat * 1000);

//	pthread_mutex_unlock(philo->left_fork); /*libere la fork*/
//	pthread_mutex_unlock(philo->right_fork);
//}

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
	print_msg(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	printf("Philo %d is thinking\n", philo->id);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("Philo %d %s\n", philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
}
