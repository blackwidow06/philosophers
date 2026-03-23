/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:36:00 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/23 11:39:33 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	if (parse_args(&data, argc, argv))
		return (1);
	if (init_forks(&data))
		return (1);
	philo = malloc(sizeof(t_philo) * data.number_of_philo);
	if (!philo)
		return (1);
	init_philos(philo, &data);
	if (create_threads(philo, &data))
		return (1);
	i = 0;
	while (i < data.number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}
