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

int	main(int argc, char **argv)
{
	//t_exec	*exec;

	//exec = (t_exec *)malloc(sizeof(t_exec));
	//if (exec == NULL)
		//return (1);
	//if (init_main (argc, argv, exec) == FALSE)
		//return (1);
	if (init_main (argc, argv) == FALSE)
		return (1);
  return (0);
}
