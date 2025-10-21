/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:06:42 by mcamilli          #+#    #+#             */
/*   Updated: 2024/02/13 20:53:03 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdint.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id_philo;
	int				meal;
	int				sated;
	int				dead;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				end_philo;
	int				doomed;
	uint64_t		time_to_die;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	struct s_data	*data;
	pthread_mutex_t	lock_dead;
	int				is_eating;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				sms_flag;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				end;
	int				sated_condition;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
	uint64_t		time;
}	t_data;

void		*timer(void *ptr);
int			ft_one_philo(t_philo *philo);
int			ft_sleeping(t_philo *philo);
void		math_sated(t_data *data);
void		*atac(void *ptr);
int			ft_atoi(char *str);
int			error(t_data *data);
int			ft_isdigit(int c);
int			ft_usleep(uint64_t time);
void		init(t_data *data, int ac, char **av);
void		init_philos(t_data *data);
void		init_fork(t_data *data);
void		init_threads(t_data *data);
void		ft_eat(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		*ft_routine(void *ptr);
void		alloc(t_data *data);
void		sms(t_data *data, char *str, int id);
uint64_t	get_time(void);
void		free_all(t_data *data);
int			ft_kill_all(t_data *data, int i);

#endif
