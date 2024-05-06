/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:36:25 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/14 17:49:41 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isspace(const char *str, size_t *pi)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*pi = i;
	return (sign);
}

static size_t	plus_overflow_check(long num, int sign, const char str)
{
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (sign == 1)
	{
		if (ov_div < num)
			return (1);
		if (ov_div == num && str - '0' >= ov_mod)
			return (1);
	}
	return (0);
}

static size_t	minus_overflow_check(long num, int sign, char str)
{
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MIN / 10;
	ov_mod = LONG_MIN % 10;
	if (sign == -1)
	{
		if (ov_div * (-1) < num)
			return (1);
		if (num == ov_div * (-1) && str - '0' >= ov_mod * (-1))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	pi;
	long	num;
	int		sign;

	sign = st_isspace(str, &pi);
	i = pi;
	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (plus_overflow_check(num, sign, str[i]) == 1 && sign == 1)
			return ((int)LONG_MAX);
		if (minus_overflow_check(num, sign, str[i]) == 1 && sign == -1)
			return ((int)LONG_MIN);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return ((int)(num * sign));
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n",atoi("9223372036854775808"));
// 	printf("%d\n",ft_atoi("9223372036854775808"));
// }
