/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:57:19 by username          #+#    #+#             */
/*   Updated: 2024/06/08 17:58:18 by tofujiwa         ###   ########.fr       */
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
}