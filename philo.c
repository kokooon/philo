/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:32:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/25 14:42:54 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 == 0)
		usleep(300);
	while (1)
	{
		if (philo->info->philo_dead)
			return (NULL);
		eat_philo(philo);
		if (philo->info->philo_dead)
			return (NULL);
		print(philo, "is sleepimg");
		ft_usleep(philo->info->t_to_sleep);
		if (philo->info->philo_dead)
			return (NULL);
		print(philo, "is thinking");
		usleep(200);
	}
}

void	eat_philo(t_philo *philo)
{
	if (philo->info->philo_dead)
		return ;
	pthread_mutex_lock(&(philo->info->forks[philo->forkgauche]));
	if (philo->info->philo_dead)
		return ;
	print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->info->forks[philo->forkdroite]));
	if (philo->info->philo_dead)
		return ;
	print(philo, "has taken a fork");
	if (philo->info->philo_dead)
		return ;
	philo->t_eat = get_time();
	print(philo, "is eating");
	ft_usleep(philo->info->t_to_eat);
	pthread_mutex_unlock(&(philo->info->forks[philo->forkgauche]));
	pthread_mutex_unlock(&(philo->info->forks[philo->forkdroite]));
	philo->eat_count++;
}

int	check_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&(data->end[i]));
		if (get_time() - data->philo[i].t_eat > (long long)data->t_to_die)
		{
			data->philo_dead = 1;
			pthread_mutex_unlock(&(data->end[i]));
			pthread_mutex_lock(&(data->print));
			printf("%llu %d %s\n", get_time()
				- data->t_start, data->philo[i].num, "is dead");
			return (1);
		}
		pthread_mutex_unlock(&(data->end[i]));
		i++;
	}
	return (0);
}

int	check_repas(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->n_philo)
	{
		if (data->philo[i].eat_count >= data->n_eat)
			j++;
		i++;
	}
	if (data->n_philo == j)
	{
		data->philo_dead = 1;
		return (1);
	}
	return (0);
}

int	check_end(t_data *data)
{
	while (1)
	{
		if (check_dead(data) == 1)
			return (1);
		if (data->n_eat != -1)
		{
			if (check_repas(data))
				return (1);
		}
		usleep(200);
	}
	return (0);
}
