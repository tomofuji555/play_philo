/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:00:00 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 11:00:00 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_philo(t_philo *args)
// {
// 	printf ("num : %d, die : %d, eat : %d, sleep : %d, must_eat : %d \n"
// , args->exec->num, args->exec->die, args->exec->eat, args->exec->sleep, args->exec->must_eat);
// }


static void	take_fork(t_philo *philo, t_exec *exec)
{
	printf("%lu %d has taken a fork\n", \
		get_time() - exec->start_time, philo->id);
}

static void	release_fork(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&(fork->lock));
	fork->last_eat_id = philo->id;
	pthread_mutex_unlock(&(fork->lock));
}

static void	do_eat(t_philo *philo, t_exec *exec)
{
	philo->last_eat_time = get_time();
	printf("%lu %d is eating\n", \
		philo->last_eat_time - exec->start_time, philo->id);
	// msleep(exec->eat, philo, exec);
	philo->eat_count++;
}

static void	do_sleep(t_philo *philo, t_exec *exec)
{
	printf("%lu %d is sleeping\n", \
		get_time() - exec->start_time, philo->id);
	// msleep(exec->sleep, philo, exec);
}

static void	take_eat_release_sleep(t_philo *philo, t_exec *exec)
{
	take_fork(philo, exec);
	take_fork(philo, exec);
	do_eat(philo, exec);
	release_fork(philo->left, philo);
	release_fork(philo->right, philo);
	// if (is_someone_dead(exec))
	// 	return ;
	do_sleep(philo, exec);
}

void	*run(void *arg)
{
	t_philo	*philo;
	// t_exec	*exec;

	philo = (t_philo *)arg;
	while (TRUE)
	{
		while (!can_take_pair_forks(philo))
			usleep(100);
		take_eat_release_sleep(philo, philo->exec);
	}
	return (NULL);
}