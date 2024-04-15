/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:12:00 by kevi il re,       #+#    #+#             */
/*   Updated: 2024/02/13 20:47:05 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*timer(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *)ptr;
	while (philo->data->end == 0)
	{
		if (get_time() >= philo->time_to_die && !philo->is_eating)
		{
			pthread_mutex_lock(&philo->data->lock);
			pthread_mutex_lock(&philo->data->print);
			sms(philo->data, "is dead", philo->id_philo);
			philo->data->end = 1;
			pthread_mutex_unlock(&philo->data->print);
			pthread_mutex_unlock(&philo->data->lock);
			return (NULL);
		}
	}
	return (NULL);
}

int	ft_usleep(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	ft_one_philo(t_philo *philo)
{
	if (philo->doomed)
	{
		pthread_mutex_unlock(philo->fork_l);
		ft_usleep(philo->data->t_die);
		return (1);
	}
	else
		return (0);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	pthread_mutex_lock(&philo->data->print);
	sms(philo->data, "has taken a fork", philo->id_philo);
	pthread_mutex_unlock(&philo->data->print);
	if (ft_one_philo(philo))
		return ;
	pthread_mutex_lock(philo->fork_r);
	pthread_mutex_lock(&philo->data->print);
	sms(philo->data, "has taken a fork", philo->id_philo);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->lock_dead);
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->lock_dead);
	pthread_mutex_lock(&philo->data->print);
	sms(philo->data, "is eating", philo->id_philo);
	pthread_mutex_unlock(&philo->data->print);
	ft_usleep(philo->t_eat);
	pthread_mutex_lock(&philo->lock_dead);
	philo->time_to_die = get_time() + (uint64_t)philo->data->t_die;
	philo->meal++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->lock_dead);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

int	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	sms(philo->data, "is sleeping", philo->id_philo);
	pthread_mutex_unlock(&philo->data->print);
	ft_usleep(philo->t_sleep);
	return (0);
}
