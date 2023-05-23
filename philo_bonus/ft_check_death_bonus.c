/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:05:52 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 10:56:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_death(void *datatemp)
{
	t_data	*data;
	int		i;

	data = (t_data *) datatemp;
	i = 0;
	usleep(data->time_die);
	sem_wait(data->start);
	ft_kill_philo(data);
	while (i != data->nb_philo)
	{
		sem_post(data->reset);
		i++;
	}
	sem_post(data->print_m);
	return (NULL);
}
