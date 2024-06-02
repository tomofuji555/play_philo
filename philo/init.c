/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/02 17:21:39 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

t_share	*init_share(void)
{
	t_share	*share;
	int		rt;

	share = (t_share *)malloc(sizeof(t_share));
	if (share == NULL)
		return (NULL);
	share->is_dead = FALSE;
	rt = init_mutex(&(share->lock));
	if (rt != 0)
		return (NULL);
	// share->start_time = 0;
	// share->last_eat_time = 0;
	return (share);
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
