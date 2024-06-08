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

static void	take_eat_release_sleep(t_philo *philo, t_exec *exec, t_share *share)
{
	take_fork(philo, exec);
	take_fork(philo, exec);
	do_eat(philo, exec);
	release_fork(philo->left, philo);
	release_fork(philo->right, philo);
	if (is_someone_dead(share))
		return ;
	do_sleep(philo, exec);
}

// static void    print_philo(t_philo *philo)
// {
// 	pthread_mutex_lock(&(philo->share->lock)); 
//     printf("philo_id=%d;\n", philo->id);
//     // printf("laste_time=%lu;\n", philo->last_eat_time);
//     // printf("die_time=%d;\n", philo->common->die_time);
//     // printf("eat_time=%d;\n", philo->common->eat_time);
//     // printf("sleep_time=%d;\n", philo->common->sleep_time);
//     // printf("must_eat_count=%d;\n", philo->common->must_eat_count);
//     // printf("eat_count=%d;\n", philo->eat_count);
//     printf("right_fork.last_eat_id=%d;\n", philo->right->last_eat_id);
//     printf("left_fork.last_eat_id=%d;\n", philo->left->last_eat_id);
//     printf("\n\n");
// 	pthread_mutex_unlock(&(philo->share->lock));
// }

void	*run(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat_time = philo->exec->start_time;
	// print_philo(philo);
	while (!is_someone_dead(philo->share) \
			&& !is_dead(*philo, philo->share, philo->exec) \
			&& (philo->exec->must_eat == -1 \
			|| philo->eat_count < philo->exec->must_eat))
	{
		think(philo, philo->exec);
		while (!can_take_pair_forks(philo) &&
				!is_someone_dead(philo->share)
				&& !is_dead(*philo, philo->share, philo->exec))
			usleep(100);
		if (is_someone_dead(philo->share))
			return (NULL);
		take_eat_release_sleep(philo, philo->exec, philo->share);
	}
	return (NULL);
}