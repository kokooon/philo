/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:30:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/20 14:13:11 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->n_philo = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = -1;
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], \
			NULL);
		i++;
	}
	return (1);
}

int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread_id, \
			NULL, routine, &data->philo[i]))
			return (0);
		data->philo[i].t_eat = data->t_start;
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		pthread_detach(data->philo[i++].thread_id);
	return (1);
}

int	philo_init(t_data *data, int argc, char **argv)
{
	if (!init_data(data, argc, argv))
		return (0);
	data->t_start = gettime();
	if (!init_mutex(data) || !init_thread(data))
		return (0);
	return (1);
}
