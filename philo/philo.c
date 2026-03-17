/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:21:28 by malavaud          #+#    #+#             */
/*   Updated: 2026/03/17 13:21:32 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void *philosopher(void *arg)
//{
//	int id = *(int *)arg; /*recupere le numero depuis arg*/

//	while (1)
//	{
//		printf("Philosopher %d is thinking\n", id);
//		sleep(1); /*simule la duree*/
//		printf("Philosopher %d is eating\n", id);
//		sleep(1);
//		printf("Philosopher %d is sleeping\n", id);
//		sleep(1);
//	}
//	return (NULL);
//}

//int main()
//{
//	pthread_t thread1;
//	pthread_t thread2;
//	pthread_t thread3;

//	int id1 = 1; /*numero unique du philosophers*/
//	int id2 = 2;
//	int id3 = 3;

//	pthread_create(&thread1, NULL, philosopher, &id1);
//	pthread_create(&thread2, NULL, philosopher, &id2);
//	pthread_create(&thread3, NULL, philosopher, &id3);

//	pthread_join(thread1, NULL); /*attend que ca se termine*/
//	pthread_join(thread2, NULL);
//	pthread_join(thread3, NULL);

//	return (0);
//}
