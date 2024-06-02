/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:20:27 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 17:20:27 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_exec *exec, t_fork *fork, t_share *share)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * exec->num);
	if (philo == NULL)
		return (free_all(exec, fork, share, NULL));
	while (i < exec->num)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].exec = exec;
		philo[i].last_eat_time = 0;
		philo[i].share = share;
		if (i == 0)
			philo[i].right = &fork[(exec->num) - 1];
		else
			philo[i].right = &fork[i - 1];
		philo[i].left = &fork[i];
		i++;
	}
	return (philo);
}
