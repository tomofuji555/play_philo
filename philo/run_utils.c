/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:33:47 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 14:33:47 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_exec *exec)
{
	printf("%lu %d has taken a fork\n", \
		get_time() - exec->start_time, philo->id);
}

void	release_fork(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&(fork->lock));
	fork->last_eat_id = philo->id;
	pthread_mutex_unlock(&(fork->lock));
}

void	do_eat(t_philo *philo, t_exec *exec)
{
	philo->last_eat_time = get_time();
	printf("%lu %d is eating\n", \
		philo->last_eat_time - exec->start_time, philo->id);
	// msleep(exec->eat, philo, exec);
	usleep(exec->eat * 1000);
	philo->eat_count++;
}

void	do_sleep(t_philo *philo, t_exec *exec)
{
	printf("%lu %d is sleeping\n", \
		get_time() - exec->start_time, philo->id);
	usleep(exec->sleep * 1000);
	// msleep(exec->sleep, philo, exec);
}

