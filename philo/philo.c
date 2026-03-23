/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:21:28 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/23 11:33:15 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		printf("Philo %d is alive\n", philo->id);
		usleep(1000000);
	}
	return (NULL);
}

//void	*routine(void *arg)
//{
//	t_philo	*philo;

//	philo = (t_philo *)arg;
//	while (1)
//	{
//		eat(philo);
//		ft_sleep(philo);
//		think(philo);
//	}
//	return (NULL);
//}