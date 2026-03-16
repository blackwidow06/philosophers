/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:22 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/16 20:43:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO 

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_data
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
}				t_data;

/*parsing.c*/
int	parse_args(t_data *data, int argc, char **argv);

/*utils_parsing.c*/
int	ft_atoi(const char *str);
int	verif_number(char *str);

#endif