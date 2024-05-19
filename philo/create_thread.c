/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.your42netw      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:50:33 by username          #+#    #+#             */
/*   Updated: 2024/05/19 15:50:47 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_exec *exec)
{
	int			i;
	pthread_t	thread[exec->num];

	i = 0;
	while (i < exec->num)
	{
		pthread_create (&thread[i], NULL, run, &exec[i]);
		i++;
	}
	i = 0;
	while (i < exec->num)
	{
		pthread_join(thread[i], NULL); //waitみたいなもん↲
		i++;
	}
}
