/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:12:00 by kevi il re,       #+#    #+#             */
/*   Updated: 2024/02/13 20:54:07 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_it_sated(t_philo *philo)
{
	if (philo->meal >= philo->data->n_eat && philo->data->n_eat > 0)
	{
		pthread_mutex_lock(&philo->lock_dead);
		philo->sated = 1;
		pthread_mutex_unlock(&philo->lock_dead);
	}
}

void	*ft_routine(void *ptr)
{
	t_philo		*philo;
	pthread_t	delorian;

	philo = (t_philo *)ptr;
	if (pthread_create(&delorian, NULL, &timer, (void *)philo))
		return (NULL);
	if (philo->id_philo % 2 == 0)
		ft_usleep(100);
	while (philo->data->end == 0)
	{
		ft_eat(philo);
		is_it_sated(philo);
		if (philo->data->end == 1)
			break ;
		ft_sleeping(philo);
		if (philo->data->end == 1)
			break ;
		pthread_mutex_lock(&philo->data->print);
		sms(philo->data, "is thinking", philo->id_philo);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_join(delorian, NULL);
	return (NULL);
}

int	ft_atoi(char *str)
{
	long int	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		r = r * 10 + str[i++] - '0';
	}
	if (r > 2147483647 || r < -2147483647)
		return (-1);
	return (r * s);
}

int	error(t_data *data)
{
	if (data->n_philo < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0 || data->n_eat < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}
