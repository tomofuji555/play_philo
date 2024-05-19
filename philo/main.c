/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:22:06 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/18 20:30:27 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init_mainを全てmainで書く必要があるかも

bool args_check(int argc, char **argv)
{
	int num = 0;
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (argc >= 0)
		num = ft_atoi (argv[1]);
	if (num == 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_exec	*exec;
	t_philo	*philo;

	if (args_check(argc, argv) == FALSE)
		return (1);
	exec = (t_exec *)malloc(sizeof(t_exec) * ft_atoi(argv[1]));
	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (exec == NULL)
		return (1);
	if (init_main (argc, argv, exec, philo) == FALSE)
		return (1);
	//if (init_main (argc, argv) == FALSE)
		//return (1);
  return (0);
}
