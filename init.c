/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:30:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/25 14:28:16 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->n_philo = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = -1;
	data->philo_dead = 0;
	return (data);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	data->end = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->end)
		return (0);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], \
			NULL);
		pthread_mutex_init(&data->end[i], \
			NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	return (1);
}

int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo)
	{
		data->philo[i].num = (i + 1);
		data->philo[i].t_eat = data->t_start;
		data->philo[i].forkgauche = (i + 1) % data->n_philo;
		data->philo[i].forkdroite = (i + 2) % data->n_philo;
		data->philo[i].eat_count = 0;
		data->philo[i].info = data;
		if (pthread_create(&data->philo[i].thread_id, \
			NULL, routine, &data->philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		pthread_detach(data->philo[i++].thread_id);
	return (1);
}

int	philo_init(t_data *data)
{
	data->t_start = get_time();
	if (!init_mutex(data))
		return (0);
	if (!init_thread(data))
		return (0);
	return (1);
}
