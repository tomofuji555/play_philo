/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:10:12 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/08 17:59:32 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(pthread_mutex_t *mutex)
{
	int	ret;

	ret = pthread_mutex_init(mutex, NULL);
	if (ret != 0)
	{
		printf("mutex init failed\n");
		return (1);
	}
	return (ret);
}

t_ms get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (t_ms)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}