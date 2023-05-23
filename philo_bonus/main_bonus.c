/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:08:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_init_threadp(t_data *data, int nb)
{
	int	error;

	data->table[nb].nb = nb + 1;
	data->table[nb].data = data;
	data->table[nb].nb_nead_eat = data->nb_eat;
	if (data->nb_philo % 2 && nb + 1 == data->nb_philo && (nb + 1) % 3 == 1)
		data->table[nb].group = 2;
	else
		data->table[nb].group = (nb + 1) % (2 + (data->nb_philo % 2));
	error = 0;
	start_routine((void *) &(data->table[nb]));
	return (error);
}

int	ft_init_programme(t_data *data)
{
	int	i;

	i = 0;
	ft_init_sem_m(data);
	data->table = ft_calloc(data->nb_philo, sizeof(t_threadp));
	if (!data->table)
	{
		ft_close_sem_m(data);
		return (-2);
	}
	while (i != data->nb_philo)
	{
		if (ft_init_threadp(data, i))
		{
			ft_kill_philo(data);
			ft_close_sem_m(data);
			free(data->table);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		sem_wait(data->reset);
		i++;
	}
	printf("\e[0;35mSIMULATION ON\e[0;m\n");
	i = 0;
	while (i < data->nb_philo)
	{
		sem_post(data->start);
		i++;
	}
	pthread_create(&(data->death_checker), NULL,
		ft_check_death, (void *) data);
	i = 0;
	while (i != data->nb_philo)
	{
		sem_wait(data->reset);
		i++;
	}
	sem_post(data->start);
	ft_stop_simulation(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	sem_unlink("sem_fork");
	sem_unlink("sem_start");
	sem_unlink("sem_reset");
	sem_unlink("sem_print");
	sem_unlink("sem_take");
	if (ac < 5 || ac > 6)
	{
		printf("\e[0;31mWrong Number of arguments\e[0;m\n");
		return (0);
	}
	if (ft_parsing(ac, av, &data))
		return (0);
	error = ft_init_programme(&data);
	if (!error)
		ft_start_simulation(&data);
	if (error == -1)
		printf("\e[0;31mErreur : thread creation\e[0;m\n");
	if (error == -2)
		printf("\e[0;31mErreur : Malloc\e[0;m\n");
	return (0);
}
