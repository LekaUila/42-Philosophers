/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_gothink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:47:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/28 12:28:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_take_right_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = &(philo->data->fork[philo->nb - 1]);
	while (philo->group != ft_get_group(philo))
	{
		usleep(50);
		if (!ft_i_am_alive(philo))
			return (-1);
	}
	pthread_mutex_lock(fork);
	if (ft_i_am_alive(philo))
		ft_print_activity(philo, "has tacken a fork");
	return (0);
}

static int	ft_take_left_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	if (philo->nb != philo->data->nb_philo)
		fork = &(philo->data->fork[philo->nb]);
	else
		fork = &(philo->data->fork[0]);
	while (philo->group != ft_get_group(philo))
	{
		usleep(50);
		if (!ft_i_am_alive(philo))
			return (-1);
	}
	pthread_mutex_lock(fork);
	if (ft_i_am_alive(philo))
		ft_print_activity(philo, "has tacken a fork");
	return (0);
}

void	ft_release_right_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = &(philo->data->fork[philo->nb - 1]);
	pthread_mutex_unlock(fork);
}

void	ft_release_left_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	if (philo->nb != philo->data->nb_philo)
		fork = &(philo->data->fork[philo->nb]);
	else
		fork = &(philo->data->fork[0]);
	pthread_mutex_unlock(fork);
}

void	ft_p_gothink(t_philo *philo)
{
	ft_print_activity(philo, "is thinking");
	if (!ft_take_right_fork(philo))
	{
		if (ft_i_am_alive(philo))
		{		
			if (!ft_take_left_fork(philo))
			{
				if (ft_i_am_alive(philo))
					return ;
				ft_release_left_fork(philo);
			}
		}
		ft_release_right_fork(philo);
	}
}
