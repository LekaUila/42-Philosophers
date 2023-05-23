/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_am_alive_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:20:24 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 17:20:33 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_i_am_alive(t_philo *philo)
{
	unsigned long	now;

	now = (ft_gettime(philo->start_time) - philo->last_eat);
	sem_wait(philo->print_m);
	if (now > philo->time_die)
	{
		now = ft_gettime(philo->start_time);
		printf("\e[0;31m%lu %i is dead\e[0;m\n", now, philo->nb);
		sem_post(philo->start);
		ft_close_sem_p(philo);
		exit(EXIT_FAILURE);
	}
	sem_post(philo->print_m);
}
