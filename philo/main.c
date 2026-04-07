/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:36:00 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/07 14:16:39 by malavaud         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pthread_t	monitor_thread;
	t_data		data;
	t_philo		*philo;
	int			i;

	data.stop = 0;
	data.start_time = get_time();
	if (parse_args(&data, argc, argv))
		return (1);
	if (init_forks(&data))
		return (1);
	philo = malloc(sizeof(t_philo) * data.number_of_philo);
	if (!philo)
		return (1);
	data.start_time = get_time();
	init_philos(philo, &data);
	if (create_threads(philo, &data))
		return (1);
	pthread_create(&monitor_thread, NULL, monitor, philo);
	i = 0;
	while (i < data.number_of_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_join(monitor_thread, NULL);
	free_all(&data, philo);
	return (0);
}
