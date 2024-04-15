/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:47:22 by mcamilli          #+#    #+#             */
/*   Updated: 2024/02/13 20:51:23 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	alloc(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->threads = malloc(sizeof(pthread_t) * data->n_philo);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	sms(t_data *data, char *str, int id)
{
	if (data->end == 1)
		return ;
	printf("%llu %d %s\n", (get_time() - data->time), id, str);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(data->philo[i].fork_l);
		if (data->n_philo > 1)
			pthread_mutex_destroy(data->philo[i].fork_r);
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].lock_dead);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->print);
	free(data->philo);
	free(data->forks);
	free(data->threads);
}
