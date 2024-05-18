/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/06 13:59:34 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

bool	init_arg(int argc, char **argv, t_exec *exec)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	exec->num = ft_atoi (argv[1]);
	exec->die = ft_atoi (argv[2]);
	exec->eat = ft_atoi (argv[3]);
	exec->sleep = ft_atoi (argv[4]);
	if (!exec->num || !exec->die || !exec->eat \
		|| !exec->sleep)
		return (FALSE);
	if (argc == 6)
	exec->al_eat = ft_atoi (argv[5]);
	return (TRUE);
}

bool	init_fork(t_exec *exec)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	exec->fork = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * (exec->num));
	if (exec->fork == NULL)
	{
	free (exec);
	return (FALSE);
	}
	while (i < exec->num)
	{
		pthread_create (exec->fork[i], NULL, run, &cnt);
		i++;
	}
	return (TRUE);
}

void	run(int *cnt)
{
	int i = 0;
	while (i < 100)
	{
		(*cnt)++;
		i++;
	}
}

bool	init_main(int argc, char **argv, t_exec *exec)
{
	if (init_arg (argc, argv, exec) == FALSE)
		return (FALSE);
	if (init_fork (exec) == FALSE)
		return (FALSE);
	return (TRUE);
}
