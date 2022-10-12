/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:03:04 by gmarzull          #+#    #+#             */
/*   Updated: 2022/09/26 18:42:06 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(t_philo	*philo)
{
	long long	ms;

	gettimeofday(&philo->tv, NULL);
	ms = philo->tv.tv_sec * 1000 + philo->tv.tv_usec / 1000;
	return (ms);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		n;

	n = 1;
	i = 0;
	r = 0;
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (r * n > 2147483647)
			return (0);
		else if (r * n < -2147483648)
			return (-1);
		r = 10 * r + str[i] - '0';
		i++;
	}
	return (r * n);
}
