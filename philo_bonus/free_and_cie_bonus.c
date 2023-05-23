/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:10:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:08:48 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_close_sem_m(t_data *data)
{
	sem_close(data->fork);
	sem_close(data->start);
	sem_close(data->reset);
	sem_close(data->print_m);
	sem_close(data->can_take);
	sem_unlink("sem_fork");
	sem_unlink("sem_start");
	sem_unlink("sem_reset");
	sem_unlink("sem_print");
	sem_unlink("sem_take");
}

void	ft_close_sem_p(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->start);
	sem_close(philo->reset);
	sem_close(philo->print_m);
	sem_close(philo->can_take);
}

void	ft_kill_philo(t_data *data)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i != data->nb_philo)
	{
		error = kill(data->table[i].pid, SIGKILL);
		data->table[i].id = 0;
		if (error)
			printf("KILL error : philo %i\n", data->table[i].nb);
		i++;
	}
}

void	ft_stop_simulation(t_data *data)
{
	pthread_join(data->death_checker, NULL);
	ft_close_sem_m(data);
	free(data->table);
	printf("\e[0;35mSIMULATION OFF\n\e[0;m");
}
