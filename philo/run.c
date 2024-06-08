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

static void	think(t_philo *philo, t_exec *exec)
{
	printf("%lu %d is thinking\n", \
		get_time() - exec->start_time, philo->id);
}

static bool	can_take_fork(t_fork *fork, t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(&(fork->lock));
	if (fork->last_eat_id != philo->id)
		ret = TRUE;
	else
		ret = FALSE;
	pthread_mutex_unlock(&(fork->lock));
	return (ret);
}

static bool	can_take_pair_forks(t_philo *philo)
{
	return (can_take_fork(philo->left, philo)
		&& can_take_fork(philo->right, philo));
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

// void	*run(void *arg)
// {
// 	t_philo	*philo;
// 	// t_exec	*exec;

// 	philo = (t_philo *)arg;
// 	while (TRUE)
// 	{
// 		while (!can_take_pair_forks(philo))
// 			usleep(100);
// 		take_eat_release_sleep(philo, philo->exec);
// 	}
// 	return (NULL);
// }

void	*run(void *arg)
{
	t_philo	*philo;
	// t_exec	*exec;

	philo = (t_philo *)arg;
	philo->last_eat_time = philo->exec->start_time;
	while (!is_someone_dead(philo->share) \
			&& !is_dead(*philo, philo->share, philo->exec) \
			&& philo->eat_count < philo->exec->must_eat)
	{
		think(philo, philo->exec);
		while (!can_take_pair_forks(philo) && 
				!is_someone_dead(philo->share)
				&& !is_dead(*philo, philo->share, philo->exec))
			usleep(100);
		if (!is_someone_dead(philo->share) \
				&& !is_dead(*philo, philo->share, philo->exec))
			return (NULL);
		take_eat_release_sleep(philo, philo->exec);
	}
	return (NULL);
}