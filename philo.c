/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:32:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/20 14:20:15 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (NULL);
	while (1)
	{
		eat_philo(philo);
		print(philo, "is sleepimg");
		ft_usleep(philo->data->t_to_sleep);
		print(philo, "is thinking");
		usleep(200);
	}

}

int	check_dead(t_data *data)
{

}