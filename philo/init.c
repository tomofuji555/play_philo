/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/01 18:30:18 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

t_exec	*init_exec(int argc, char **argv)
{
	int		i;
	int		philo_num;
	t_exec	*exec;

	i = 0;
	philo_num = ft_atoi(argv[1]);
	exec = (t_exec *)malloc(sizeof(t_exec) * philo_num);
	// printf ("%d\n", philo_num);
	if (exec == NULL)
		return (NULL);
	while (i < philo_num)
	{
		exec[i].num = philo_num;
		exec[i].die = ft_atoi (argv[2]);
		exec[i].eat = ft_atoi (argv[3]);
		exec[i].sleep = ft_atoi (argv[4]);
		if (argc == 6)
			exec[i].must_eat = ft_atoi (argv[5]);
		else
			exec[i].must_eat = 0;
		if (!exec[i].num || !exec[i].die || !exec[i].eat || !exec[i].sleep)
			return (NULL);
// 		printf ("num : %d, die : %d, eat : %d, sleep : %d, al_eat : %d \n"
// , exec[i].num, exec[i].die, exec[i].eat, exec[i].sleep, exec[i].must_eat);
		i++;
	}
	// printf ("id: %d\n", exec->num);
	return (exec);
}

t_fork	*init_fork(t_exec *exec)
{
	//pthread_t threads[exec->num];
	t_fork	*fork;
	int		i;

	i = 0;
	fork = (t_fork *)malloc(sizeof(t_fork) * (exec->num));
	if (fork == NULL)
		return(free_all(fork, NULL, NULL, NULL));
	while (i < exec->num)
	{
		fork[i].state = 0;
		fork[i].last_eat_id = -1;
		i++;
	}
	return (fork);
}

t_share	*init_share(void)
{
	t_share	*share;

	share = (t_share *)malloc(sizeof(t_share));
	if (share == NULL)
		return (NULL);
	share->is_dead = FALSE;
	return (share);
}

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
		philo->id = i + 1;
		philo->eat_count = 0;
		philo->exec = exec;
		// printf ("%d\n", philo->exec->num);
		philo->last_eat = 0;
		philo->share = share;
		if (i == 0)
			philo[i].right = fork[(exec->num) - 1];
		else
			philo[i].right = fork[i - 1];
		philo[i].left = fork[i];
		i++;
		// printf ("num: %d die: %d eat : %d sleep: %d must_eat: %d\n", philo->exec->num, philo->exec->die, philo->exec->eat, philo->exec->sleep, philo->exec->must_eat);
	}
	return (philo);
}

void	print_exec(t_philo *args)
{
	printf ("num : %d, die : %d, eat : %d, sleep : %d, must_eat : %d \n"
, args->exec->num, args->exec->die, args->exec->eat, args->exec->sleep, args->exec->must_eat);
}

void	*run(void *philo)
{
	t_philo	*exec;

	exec = (t_philo *)philo;
	// int i = 0;
	// while (i < 100)
	// {
	// 	num->num = 3;
	// 	i++;
	// }
	print_exec(exec);
	return (NULL);
}

// bool	init_main(int argc, char **argv, t_exec *exec, t_philo *philo)
// {
// 	//t_exec	*exec;

// 	//exec = (t_exec *)malloc(sizeof(t_exec) * (ft_atoi(argv[1])));
// 	if (init_exec (argc, argv, exec) == FALSE)
// 		return (FALSE);
// 	if (init_fork (exec) == FALSE)
// 		return (FALSE);
// 	if (init_philo(exec, philo) == FALSE)
// 		return (FALSE);
// 	create_thread(exec);
// 	return (TRUE);
// }

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
