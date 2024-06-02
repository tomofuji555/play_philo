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

bool	can_take_pair_forks(t_philo *philo)
{
	return (can_take_fork(philo->left, philo)
		&& can_take_fork(philo->right, philo));
}
