/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_share.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:32 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/08 17:58:39 by tofujiwa         ###   ########.fr       */
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
	return (share);
}
