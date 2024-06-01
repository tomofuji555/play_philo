/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:10:12 by tofujiwa          #+#    #+#             */
/*   Updated: 2024/06/01 18:00:30 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

bool is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	num;
	// sign = st_isspace(str, &pi);
	i = 0;
	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (num > (INT_MAX / 10)
			|| (num == (INT_MAX / 10) && (*str - '0') > (INT_MAX % 10)))
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}
