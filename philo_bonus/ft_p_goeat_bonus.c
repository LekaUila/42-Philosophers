/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_goeat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:48:08 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:12:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	while (now < end)
	{
		usleep(50);
		ft_i_am_alive(philo);
		now = ft_gettime(start_time);
	}
	sem_post(philo->fork);
	sem_post(philo->fork);
	philo->nb_eat++;
	if (philo->nb_nead_eat == philo->nb_eat && philo->nb_nead_eat != -1)
	{
		sem_post(philo->reset);
		ft_close_sem_p(philo);
		exit(EXIT_SUCCESS);
	}
}
