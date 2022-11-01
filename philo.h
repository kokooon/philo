/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:04:11 by gmarzull          #+#    #+#             */
/*   Updated: 2022/10/24 18:27:16 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_data;

typedef struct s_philo
{
	int				num;
	int				eat_count;
	long long		t_eat;
	struct s_data	*info;
	int				forkgauche;
	int				forkdroite;
	pthread_t		thread_id;
}			t_philo;

typedef struct s_data
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		*end;
	pthread_mutex_t		print;
	int					n_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					n_eat;
	int					id;
	int					philo_dead;
	long long			t_start;
	struct s_philo		*philo;
}			t_data;

//check.c
int			check_all(char **argv);
int			check_nb(char **argv);
int			check_min(char **argv);

//philo.c
void		*routine(void *arg);
int			check_dead(t_data *data);
int			check_repas(t_data *data);
void		eat_philo(t_philo *philo);
int			check_end(t_data *data);

//main.c

//init.c
t_data		*init_data(int argc, char **argv);
int			philo_init(t_data *data);
int			init_mutex(t_data *data);
int			init_thread(t_data *data);

//functions.c
int			ft_atoi(const char *str);
long long	get_time(void);
void		print(t_philo *philo, char *str);
void		ft_usleep(long long time);
void		free_all(t_data *data);

#endif