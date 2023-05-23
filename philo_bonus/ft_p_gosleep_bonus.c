/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_gosleep_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:47:43 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/03 16:01:59 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_p_gosleep(t_philo *philo)
{
	t_time				start_time;
	unsigned long int	end;
	unsigned long int	now;

	start_time = philo->start_time;
	end = ft_print_activity(philo, "is sleeping");
	now = end;
	end += philo->time_sleep;
	while (now < end)
	{
		ft_i_am_alive(philo);
		usleep(50);
		now = ft_gettime(start_time);
	}
}
