/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:21:17 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/17 13:21:17 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	nbr *= sign;
	return (nbr);
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	free_all(t_data *data, t_philo *philo)
{
	int	i;

	if (!data || !philo)
		return ();
	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_destroy(&philo[i++].meal_mutex);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->stop_mutex);
	free(philo);
}
