/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:37:16 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/31 16:38:22 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec * 1000);
}

void	*monitor(void *arg)
{
	int		i;
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo[0].data->number_of_philo)
		{
			if (get_time() - philo[i].last_meal > philo[i].data->time_to_die)
			{
				print_msg(&philo[i], "died");
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
