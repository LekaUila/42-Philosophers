/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_am_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:20:24 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 17:20:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_i_am_alive(t_philo *philo)
{
	unsigned long	now;

	pthread_mutex_lock(&philo->data->p_isdie_m);
	if (philo->data->p_isdie)
	{
		pthread_mutex_unlock(&philo->data->p_isdie_m);
		return (0);
	}
	now = (ft_gettime(philo->start_time) - philo->last_eat);
	if (now > philo->time_die)
	{
		philo->data->p_isdie = 1;
		pthread_mutex_lock(&philo->data->print_m);
		now = ft_gettime(philo->start_time);
		printf("\e[0;31m%lu %i is dead\e[0;m\n", now, philo->nb);
		pthread_mutex_unlock(&philo->data->print_m);
		pthread_mutex_unlock(&philo->data->p_isdie_m);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->p_isdie_m);
	return (1);
}
