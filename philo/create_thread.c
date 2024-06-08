/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:50:33 by username          #+#    #+#             */
/*   Updated: 2024/06/08 18:03:28 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread_wrap(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	int	rt;

	rt = pthread_create(thread, NULL, routine, arg);
	if (rt != 0)
		printf("Error\n");
	return (rt);
}

void	create_thread(t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = (pthread_t *)malloc(sizeof(thread) * philo->exec->num);
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
	free(thread);
}
