/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:09:56 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/19 13:37:02 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->number_of_philo) /*mutex*/
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0) /*active les mutex*/
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	return (0);
}

void	init_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].nbr_meals = 0;
		philo[i].last_meal = 0;
		philo[i].data = data;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->number_of_philo];
		i++;
	}
}

