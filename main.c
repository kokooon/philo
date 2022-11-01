/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:24:50 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/22 15:33:48 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		printf("Error : Wrong arguments number.\n");
		return (0);
	}
	data = init_data(argc, argv);
	if (data == NULL)
		return (0);
	if (!check_all(argv))
		return (0);
	if (philo_init(data))
		check_end(data);
	free_all(data);
	return (0);
}
