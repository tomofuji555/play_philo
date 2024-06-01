/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:57:19 by username          #+#    #+#             */
/*   Updated: 2024/06/01 15:51:09 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_all(void *exec, void *philo, void *fork, void *share)
{
	if (exec != NULL)
		free(exec);
	if (philo != NULL)
		free(philo);
	if (fork != NULL)
		free(fork);
	if (share != NULL)
		free(share);
	return (NULL);
	// int i;

	// i = 0;
	// while (i < exec->num)
	// {
	// 	pthread_mutex_destroy(&fork[i].lock);
	// 	i++;
	// }
}