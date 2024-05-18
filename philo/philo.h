/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:20:54 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/18 20:46:56 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
//# include <sys/_pthread/_pthread_mutex_t.h>

#define TRUE 1
#define FALSE 0

#define my_catch
#define my_not_catch
#define nobody_catch

typedef struct s_exec
{
  int             num;
  int             die;
  int             eat;
  int             sleep;
  int             al_eat;
  pthread_mutex_t *fork;
} t_exec;

typedef struct s_fork
{
  pthread_mutex_t *fork;
  int state;
  int val
} t_fork;

//typedef struct s_fork
//{
//
//} t_fork;

int		ft_atoi(const char *str);
bool	init_arg(int argc, char **argv, t_exec *exec);
bool	init_fork(t_exec *exec);
//bool	init_main(int argc, char **argv, t_exec *exec);
bool	init_main(int argc, char **argv);
void	*run(void *exec);
void	print_exec(t_exec *args);

#endif
