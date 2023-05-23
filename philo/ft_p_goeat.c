/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_goeat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:48:08 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 15:36:06 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_p_goeat(t_philo *philo)
{
	t_time				start_time;
	unsigned long int	end;
	unsigned long int	now;

	start_time = philo->start_time;
	end = ft_print_activity(philo, "is eating");
	philo->last_eat = end;
	now = end;
	end += philo->time_eat;
	while (now < end && ft_i_am_alive(philo))
	{
		usleep(50);
		now = ft_gettime(start_time);
	}
	pthread_mutex_lock(&philo->data->nb_eat_group_m);
	philo->data->nb_eat_group++;
	pthread_mutex_unlock(&philo->data->nb_eat_group_m);
	ft_release_left_fork(philo);
	ft_release_right_fork(philo);
}
