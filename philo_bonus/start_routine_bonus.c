/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:35 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:09:41 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

	free(philo->data->table);
	ft_create_planning(tab_activity);
	sem_post(philo->reset);
	sem_wait(philo->start);
	i = 0;
	gettimeofday(&(philo->start_time), NULL);
	if (philo->group == 1)
		i = 2;
	else if (philo->group == 2)
	{
		i = 1;
		ft_p_gothink_spe(philo);
	}
	while (1)
	{
		ft_i_am_alive(philo);
		tab_activity[i](philo);
		i++;
		if (i == 3)
			i = 0;
	}
}

void	ft_init_philo(t_threadp *threadp, t_philo *philo)
{
	philo->nb = threadp->nb;
	philo->data = threadp->data;
	philo->nb_nead_eat = threadp->nb_nead_eat;
	philo->time_die = threadp->data->time_die;
	philo->time_eat = threadp->data->time_eat;
	philo->time_sleep = threadp->data->time_sleep;
	philo->start = threadp->data->start;
	philo->reset = threadp->data->reset;
	philo->print_m = threadp->data->print_m;
	philo->can_take = threadp->data->can_take;
	philo->fork = threadp->data->fork;
	philo->group = threadp->group;
	philo->nb_eat = 0;
	philo->last_eat = 0;
}

void	*start_routine(void *datatemp)
{
	t_threadp	*threadp;
	t_philo		philo;
	pid_t		pid;

	threadp = (t_threadp *) datatemp;
	ft_init_philo(threadp, &philo);
	pid = fork();
	if (pid == 0)
	{
		ft_cycle(&philo);
		exit(EXIT_SUCCESS);
	}
	threadp->pid = pid;
	return (NULL);
}
