/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sem_m_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:01:00 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:29:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_init_sem_m_bis(t_data *data)
{
	data->reset = sem_open("sem_reset", O_CREAT, S_IRWXU | S_IRWXG, 0);
	if (data->reset == SEM_FAILED)
	{
		ft_close_sem_m(data);
		ft_error("\e[0;31mErreur : Sem creation\e[0;m\n");
	}
	if (data->nb_philo % 2)
		data->can_take = sem_open("sem_take", O_CREAT, S_IRWXU | S_IRWXG,
				data->nb_philo / 3);
	else
		data->can_take = sem_open("sem_take", O_CREAT, S_IRWXU | S_IRWXG,
				data->nb_philo / 2);
	if (data->can_take == SEM_FAILED)
		ft_close_sem_m(data);
	if (data->can_take == SEM_FAILED)
		ft_error("\e[0;31mErreur : Sem creation\e[0;m\n");
}

void	ft_init_sem_m(t_data *data)
{
	data->fork = sem_open("sem_fork", O_CREAT, S_IRWXU | S_IRWXG,
			data->nb_philo);
	if (data->fork == SEM_FAILED)
		ft_error("\e[0;31mErreur : Sem creation\e[0;m\n");
	data->print_m = sem_open("sem_print", O_CREAT, S_IRWXU | S_IRWXG, 1);
	if (data->print_m == SEM_FAILED)
		ft_close_sem_m(data);
	if (data->print_m == SEM_FAILED)
		ft_error("\e[0;31mErreur : Sem creation\e[0;m\n");
	data->start = sem_open("sem_start", O_CREAT, S_IRWXU | S_IRWXG, 0);
	if (data->start == SEM_FAILED)
	{
		ft_close_sem_m(data);
		ft_error("\e[0;31mErreur : Sem creation\e[0;m\n");
	}
	ft_init_sem_m_bis(data);
}
