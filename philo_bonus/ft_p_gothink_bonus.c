/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_gothink_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:47:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/03 20:14:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_p_gothink_spe(t_philo *philo)
{
	t_time				start_time;
	unsigned long int	end;
	unsigned long int	now;

	start_time = philo->start_time;
	end = ft_print_activity(philo, "is thinking");
	now = end;
	end += philo->time_sleep + philo->time_eat;
	while (now < end || philo->data->nb_philo == 1)
	{
		ft_i_am_alive(philo);
		usleep(50);
		now = ft_gettime(start_time);
	}
	sem_wait(philo->can_take);
	ft_i_am_alive(philo);
	sem_wait(philo->fork);
	ft_print_activity(philo, " has taken a fork");
	sem_wait(philo->fork);
	ft_print_activity(philo, " has taken a fork");
	sem_post(philo->can_take);
}

void	ft_p_gothink(t_philo *philo)
{
	ft_print_activity(philo, "is thinking");
	sem_wait(philo->can_take);
	ft_i_am_alive(philo);
	sem_wait(philo->fork);
	ft_print_activity(philo, " has taken a fork");
	sem_wait(philo->fork);
	ft_print_activity(philo, " has taken a fork");
	sem_post(philo->can_take);
}

/*

gothink old

void	ft_p_gothink(t_philo *philo)
{
	ft_print_activity(philo, "is thinking");
	if (philo->nb % 2)
	{
		ft_take_right_fork(philo);
		if (ft_i_am_alive(philo))
		{		
			ft_take_left_fork(philo);
			if (ft_i_am_alive(philo))
				return ;
			ft_release_left_fork(philo);
		}
		ft_release_right_fork(philo);
	}
	else
	{
		ft_take_left_fork(philo);
		if (ft_i_am_alive(philo))
		{		
			ft_take_right_fork(philo);
			if (ft_i_am_alive(philo))
				return ;
			ft_release_right_fork(philo);
		}
		ft_release_left_fork(philo);
	}
}

*/