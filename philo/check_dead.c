/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:33:05 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/08 14:33:05 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void    msleep(int ms_time, t_philo philo, t_share *share, t_exec *exec)
// {
//     t_ms    limit; //終わらせたい時間

//     limit = get_time() + ms_time;
//     if (ms_time == 0)
//         return ;
//     while (!is_someone_dead(share) \
//         && !is_dead(philo, share, exec) \
//         && get_time() < limit)
//         usleep(100);
// }

bool	is_dead(t_philo philo, t_share *share, t_exec *exec)
{
	if ((int)(get_time() - philo.last_eat_time) > exec->die)
	{
		pthread_mutex_lock(&(share->lock));
		share->is_dead = TRUE;
		pthread_mutex_unlock(&(share->lock));
		printf("%lu %d died\n", get_time() - (exec->start_time), philo.id);
		return (TRUE);
	}
	return (FALSE);
}

bool	is_someone_dead(t_share *share)
{
	bool	ret;

	pthread_mutex_lock(&(share->lock));
	ret = share->is_dead;
	pthread_mutex_unlock(&(share->lock));
	return (ret);
}