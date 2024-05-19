/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/18 20:43:11 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

bool	init_exec(int argc, char **argv, t_exec *exec)
{
	int i = 0;
	while (i < ft_atoi(argv[1]))
	{
		exec[i].num = ft_atoi (argv[1]);
		exec[i].die = ft_atoi (argv[2]);
		exec[i].eat = ft_atoi (argv[3]);
		exec[i].sleep = ft_atoi (argv[4]);
		if (!exec[i].num || !exec[i].die || !exec[i].eat 
				|| !exec[i].sleep)
			return (FALSE);
		if (argc == 6)
			exec[i].al_eat = ft_atoi (argv[5]);
		else
			exec[i].al_eat = -1;
		i++;
	}
	return (TRUE);
}

bool	init_fork(t_exec *exec)
{
	//pthread_t threads[exec->num];
	t_fork *fork;
	int i = 0;

	//exec->fork = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * (exec->num));	
	fork = (t_fork *)malloc(sizeof(t_fork) * (exec->num));
	if (fork == NULL)
	{
		free (exec);
		return (FALSE);
	}
	while (i < exec->num)
	{
		//fork->lock = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t));
		fork[i].state = 0;
		fork[i].last_eat_id = -1;
		//printf ("i : %d %d\n", fork[i].state, fork[i].last_eat_id);
		i++;
	}
	return (TRUE);
}

bool	init_philo(t_exec *exec, t_fork *fork, t_philo *philo)
{
	int i;

	i = 0;
	while (i < exec->num)
	{
		if (i == 0)
			philo[i].right = fork[(exec->num) - 1];
		else
			philo[i].right = fork[i - 1];
		exec[i].left = fork[i];
		i++;
	}
	return (TRUE);
}

void	print_exec(t_exec *args)
{
	printf ("num : %d, die : %d, eat : %d, sleep : %d, al_eat : %d \n"
, args->num, args->die, args->eat, args->sleep, args->al_eat);
}

void	*run(void *args)
{
	t_exec	*exec = (t_exec *)args;

	//int i = 0;
	//while (i < 100)
	//{
	//	num->num = 3;
	//	i++;
	//}
	print_exec(exec);
	return (NULL);
}

bool	init_main(int argc, char **argv, t_exec *exec, t_philo *philo)
{
	//t_exec	*exec;

	//exec = (t_exec *)malloc(sizeof(t_exec) * (ft_atoi(argv[1])));
	if (init_exec (argc, argv, exec) == FALSE)
		return (FALSE);
	if (init_fork (exec) == FALSE)
		return (FALSE);
	if (init_philo(exec, philo) == FALSE)
		return (FALSE);
	create_thread(exec);
	return (TRUE);
}

//bool	init_main(int argc, char **argv, t_exec *exec)
//{
//
//	if (init_arg (argc, argv, exec) == FALSE)
//		return (FALSE);
//	if (init_fork (exec) == FALSE)
//		return (FALSE);
//	printf ("%d\n", exec->num);
//	return (TRUE);
//}
