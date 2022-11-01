/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:03:04 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/24 18:27:55 by gmarzull         ###   ########.fr       */
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
	pthread_mutex_lock(&(philo->info->print));
	printf("%llu %d %s\n", get_time()
		- philo->info->t_start, philo->num, str);
	pthread_mutex_unlock(&(philo->info->print));
}

void	ft_usleep(long long time)
{
	long long	livetime;

	livetime = get_time();
	usleep(time * 900);
	while (time > get_time() - livetime)
		usleep(90);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_join(data->philo[i++].thread_id, NULL);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_unlock(&(data->forks[i]));
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_unlock(&(data->end[i]));
		pthread_mutex_destroy(&(data->end[i]));
		i++;
	}
	pthread_mutex_unlock(&data->print);
	pthread_mutex_destroy(&(data->print));
	free(data->philo);
	free(data->forks);
	free(data->end);
	free(data);
}
