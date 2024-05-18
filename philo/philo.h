/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:20:54 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/04 15:20:56 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/_pthread/_pthread_mutex_t.h>

#define TRUE 1
#define FALSE 0

typedef struct s_exec
{
  int             num;
  int             die;
  int             eat;
  int             sleep;
  int             al_eat;
  pthread_mutex_t *fork;
} t_exec;

//typedef struct s_fork
//{
//
//} t_fork;

int		ft_atoi(const char *str);
bool	init_arg(int argc, char **argv, t_exec *exec);
bool	init_fork(t_exec *exec);
bool	init_main(int argc, char **argv, t_exec *exec);
void	run(int *cnt);

#endif
