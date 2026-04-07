/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:48:10 by malavaud          #+#    #+#             */
/*   Updated: 2026/04/07 14:07:56 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	take_forks(philo);
	if (release_forks(philo))
		return ;
	eat_and_release(philo);
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
