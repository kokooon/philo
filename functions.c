/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:03:04 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/20 14:16:58 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
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

void	print(t_philo *philo, char *str)
{
	printf("%llu %d %s\n", get_time()
		- philo->data->t_start, philo->num, str);
}

void	ft_usleep(long long time)
{
	long long	livetime;

	livetime = get_time();
	usleep(time * 900);
	while (time > get_time() - livetime)
		usleep(90);
}
