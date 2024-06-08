/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:22:06 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/08 15:34:21 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init_mainを全てmainで書く必要があるかも

bool args_check(int argc, char **argv)
{
	int i;
	int num;

	i = 1;
	num = 0;
	if (argc != 5 && argc != 6)
		return (FALSE);
	while (argv[i])
	{
		if (!is_num(argv[i]))
		{
			return (FALSE);
			// printf ("Error: invalid argument\n");
		}
		i++;
	}
	// if (argc >= 2)
	num = ft_atoi (argv[1]);
	if (num == 0)
		return (FALSE);
	// printf ("argc: %d\n", argc);
	return (TRUE);
}

int	sub_main(int argc, char **argv)
{
	t_exec		*exec;
	t_philo		*philo;
	t_fork 		*fork;
	// pthread_t	*threads;
	t_share		*share;

	exec = init_exec(argc, argv);
	if (exec == NULL)
		return (0);
	fork = init_fork(exec);
	if (fork == NULL)
		return (0);
	share = init_share();
	if (share == NULL)
		return (0);
	philo = init_philo(exec, fork, share);
	if (philo == NULL)
		return (0);
	philo->exec->start_time = get_time();
	create_thread(philo);
	return (1);
}

int	main(int argc, char **argv)
{
	//t_exec		*exec;
	//t_philo		*philo;
	//t_forks 	*forks;
	//pthread_t	*threads;
	//t_share		*share;

	if (args_check(argc, argv) == FALSE)
		return (1);
	if (!sub_main(argc, argv))
		return (1);
	//exec = (t_exec *)malloc(sizeof(t_exec) * ft_atoi(argv[1]));
	//if (exec == NULL)
		//return (1);
	//philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	//if (philo == NULL)
		//return (1);
	//if (!init_exec(argc, argv, exec) || !init_fork(exec)
		//|| !init_philo(exec, fork, philo))
		//return (1);
	return (0);
}
