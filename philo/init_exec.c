/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:21:13 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 17:21:13 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exec	*init_exec(int argc, char **argv)
{
	int		i;
	int		philo_num;
	t_exec	*exec;

	i = 0;
	philo_num = ft_atoi(argv[1]);
	exec = (t_exec *)malloc(sizeof(t_exec) * philo_num);
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
			exec[i].must_eat = -1;
		if (!exec[i].num || !exec[i].die || !exec[i].eat || !exec[i].sleep)
		{
			printf("Error\n");
			return (free_all (exec, NULL, NULL, NULL));
		}
		i++;
	}
	return (exec);
}