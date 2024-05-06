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
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_exec
{
  int p_num;
  int die;
  int eat;
  int sleep;
  int al_eat;
} t_exec;

#endif
