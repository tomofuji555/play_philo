/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:58:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 08:58:38 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_last_id_case_odd(int *array, int length){
	int i;
	int num;

	i = 0;
	num = 2;
	while (i < length - 3)
	{
		array[i] = num;
		array[i + 1] = num;
		num = num + 2;
		i = i + 2;
	}
	array[i++] = num++;
	array[i++] = num;
	array[i] = num;	
}

static void	set_last_id_case_even(int *array, int length){
	int i;
	int num;

	i = 0;
	num = 2;
	while (i < length)
	{
		array[i] = num;
		array[i + 1] = num;
		num = num + 2;
		i = i + 2;
	}
}

static int	*set_last_eat_id_main(int philo_num){
	int *array;

	array = (int *)malloc(sizeof(int) * philo_num);
	if (array == NULL)
		return (NULL);
	if (philo_num % 2 == 0)
		set_last_id_case_even(array, philo_num);
	else
		set_last_id_case_odd(array, philo_num);
	return (array);
}

t_fork	*init_fork(t_exec *exec)
{
	t_fork	*fork;
	int		i;
	int		is_error;
	int		*last_eat_id;

	i = 0;
	fork = (t_fork *)malloc(sizeof(t_fork) * (exec->num));
	if (fork == NULL)
		return(free_all(exec, NULL, NULL, NULL));
	last_eat_id = set_last_eat_id_main(exec->num);
	if (!last_eat_id)
		return (free_all(fork, exec, NULL, NULL));
	while (i < exec->num)
	{
		fork[i].state = 0;
		is_error = init_mutex(&(fork[i].lock));
		if (is_error == 1)
		 	return (free_all(fork, last_eat_id, exec, NULL));
		fork[i].last_eat_id = last_eat_id[i];
		i++;
	}
	free (last_eat_id);
	return (fork);
}