/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:20:54 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/01 19:36:40 by tofujiwa         ###   ########.fr       */
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

typedef unsigned long t_m;
// typedef struct s_m
// {
// 	unsigned long	sec;
// 	unsigned long	usec;
// }	t_m;

typedef struct s_fork
{
	pthread_mutex_t	*lock;
	int				state;
	//int				val;
	int				last_eat_id;
}	t_fork;

typedef struct s_exec
{
	int		num;
	int		die;
	int		eat;
	int		sleep;
	int		must_eat;
	// t_fork	right; //philo構造体つくったのでいらない
	// t_fork	left; //philo構造体つくったのでいらない
	//pthread_mutex_t *fork;
	t_fork	*fork;
}	t_exec;

//哲学者が死んだかどうかを判定するための構造体
typedef struct s_share
{
	pthread_mutex_t		*lock;
	bool				is_dead;
	// int					philo_id; //-1で初期化する
} t_share;

typedef struct s_philo
{
	t_exec	*exec;
	t_share	*share;
	int		id;
	int		eat_count;
	t_m		start_eat;
	t_m 	last_eat;
	t_fork	right;
	t_fork	left;
} t_philo;

bool	is_num(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_exec	*init_exec(int argc, char **argv);
t_fork	*init_fork(t_exec *exec);
t_share	*init_share(void);
t_philo	*init_philo(t_exec *exec, t_fork *fork, t_share *share);
// bool	init_main(int argc, char **argv, t_exec *exec, t_philo *philo);
//bool	init_main(int argc, char **argv);
int		sub_main(int argc, char **argv);
bool 	args_check(int argc, char **argv);
int		create_thread_wrap(pthread_t *thread, void *(*routine)(void *), void *arg);
void	*run(void *exec);
void	print_exec(t_philo *args);
bool	args_check(int argc, char **argv);
void	create_thread(t_philo *philo);
void	*free_all(void *exec, void *philo, void *fork, void *share);

#endif
