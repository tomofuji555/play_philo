/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/05/06 13:59:34 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool  init_arg(int argc, char **argv, t_exec *exec)
{
  if (argc != 5 && argc != 6)
    return (FALSE);
  exec->p_num = ft_atoi (argv[1]);
  exec->die = ft_atoi (argv[2]);
  exec->eat = ft_atoi (argv[3]);
  exec->sleep = ft_atoi (argv[4]);
  if (!exec->p_num || !exec->die || !exec->eat \
      || !exec->sleep)
    return (FALSE);
  if (argc == 6)
    exec->al_eat = ft_atoi (argv[5]);
  return (TRUE);
}
