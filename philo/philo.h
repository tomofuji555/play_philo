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
	int		al_eat;
	t_fork	right; //philo構造体つくったのでいらない
	t_fork	left; //philo構造体つくったのでいらない
	//pthread_mutex_t *fork;
	t_fork	*fork;
}	t_exec;

//哲学者が死んだかどうかを判定するための構造体
typedef struct s_share
{
	pthread_mutex_t		*lock;
	bool				is_dead;
	int					philo_id; //-1で初期化する
} t_share;

typedef struct s_philo
{
	int		id;
	t_fork	right;
	t_fork	left;
} t_philo;

int		ft_atoi(const char *str);
bool	init_exec(int argc, char **argv, t_exec *exec);
bool	init_fork(t_exec *exec);
bool	init_main(int argc, char **argv, t_exec *exec, t_philo *philo);
//bool	init_main(int argc, char **argv);
void	*run(void *exec);
void	print_exec(t_exec *args);
bool	args_check(int argc, char **argv);
void	create_thread(t_exec *exec);

#endif
