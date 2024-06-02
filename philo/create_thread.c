/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:50:33 by username          #+#    #+#             */
/*   Updated: 2024/06/02 16:58:34 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread_wrap(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	int	rt;

	rt = pthread_create(thread, NULL, routine, arg);
	if (rt != 0)
		printf("Error: pthread_create() failed\n");
	return (rt);
}

void	create_thread(t_philo *philo)
{
	int			i;
	pthread_t	thread[philo->exec->num];

	i = 0;
	// printf ("num: %d\n", philo->exec->num);
	while (i < philo->exec->num)
	{
		create_thread_wrap (&thread[i], run, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->exec->num)
	{
		pthread_join(thread[i], NULL); //waitみたいなもん↲
		i++;
	}
}
