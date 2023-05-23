/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:35 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 15:35:26 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_create_planning(void (*tab_activity[3])(t_philo *philo))
{
	tab_activity[0] = ft_p_gothink;
	tab_activity[1] = ft_p_goeat;
	tab_activity[2] = ft_p_gosleep;
}

static void	ft_cycle(t_philo *philo)
{
	int		i;
	void	(*tab_activity[3])(t_philo *philo);

	ft_create_planning(tab_activity);
	i = 0;
	gettimeofday(&(philo->start_time), NULL);
	while (ft_i_am_alive(philo))
	{
		tab_activity[i](philo);
		i++;
		if (i == 3)
			i = 0;
	}
}

void	*start_routine(void *datatemp)
{
	t_philo	*philo;

	philo = datatemp;
	pthread_mutex_lock(&philo->data->p_isdie_m);
	while (philo->data->p_isdie)
	{
		if (philo->data->p_isdie == 2)
			return (NULL);
		pthread_mutex_unlock(&philo->data->p_isdie_m);
		usleep(50);
		pthread_mutex_lock(&philo->data->p_isdie_m);
	}
	pthread_mutex_unlock(&philo->data->p_isdie_m);
	ft_cycle(philo);
	return (NULL);
}
