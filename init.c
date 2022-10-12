/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:30:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/12 17:18:33 by gmarzull         ###   ########.fr       */
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
	data->n_eat = 0;
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	//???
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	while (i < data->n_philo)
	{
		data->fork[i] = pthread_create(&data->philo[i], \
			NULL, routine, NULL);
		i++;
	}
}

int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc (sizeof(pthread_t) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo)
	{
		data->philo[i].thread_id = pthread_create(&data->philo[i], \
			NULL, routine, NULL);
		i++;
	}
	return (1);
}

int	philo_init(t_data *data, int argc, char **argv)
{
	if (!init_data(data, argc, argv))
		return (0);
	gettimeofday(&data->t_start, NULL);
	if (!init_mutex(data) || !init_thread(data))
		return (0);
	return (1);
}
