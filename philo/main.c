/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 17:31:10 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_data *data, int nb)
{
	int	error;

	data->table[nb].nb = nb + 1;
	data->table[nb].data = data;
	data->table[nb].time_die = data->time_die;
	data->table[nb].time_sleep = data->time_sleep;
	data->table[nb].time_eat = data->time_eat;
	data->table[nb].last_eat = 0;
	if (data->nb_philo % 2 && nb + 1 == data->nb_philo && (nb + 1) % 3 == 1)
		data->table[nb].group = 2;
	else
		data->table[nb].group = (nb + 1) % (2 + (data->nb_philo % 2));
	error = pthread_create(&(data->table[nb].id), NULL,
			start_routine, (void *) &(data->table[nb]));
	if (error)
		data->p_isdie = 2;
	return (error);
}

void	ft_routine(t_data *data)
{
	data->p_isdie = 0;
	while (!data->p_isdie)
	{
		pthread_mutex_unlock(&data->p_isdie_m);
		pthread_mutex_lock(&data->nb_eat_group_m);
		if (ft_check_nb_eat(data) && data->nb_philo != 1)
		{
			if (data->group == 1 + (data->nb_philo % 2))
				data->nb_eat_count++;
			data->group = (data->group + 1) % (2 + (data->nb_philo % 2));
			data->nb_eat_group = 0;
		}
		pthread_mutex_unlock(&data->nb_eat_group_m);
		pthread_mutex_lock(&data->p_isdie_m);
		if (data->nb_eat != -1 && data->nb_eat == data->nb_eat_count)
		{
			data->p_isdie = 1;
		}
		pthread_mutex_unlock(&data->p_isdie_m);
		usleep(50);
		pthread_mutex_lock(&data->p_isdie_m);
	}
}

int	ft_init_programme(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	data->table = ft_calloc(data->nb_philo, sizeof(t_philo));
	if (!data->fork || !data->table)
	{
		free(data->fork);
		free(data->table);
		return (-2);
	}
	pthread_mutex_init(&data->p_isdie_m, NULL);
	while (i != data->nb_philo)
	{
		if (ft_init_philo(data, i))
		{
			ft_destroy_fork(data->nb_philo, data->fork);
			free(data->table);
			pthread_mutex_destroy(&data->p_isdie_m);
			return (-1);
		}
		pthread_mutex_init(&(data->fork[i]), NULL);
		i++;
	}
	return (0);
}

void	ft_start_simulation(t_data *data)
{
	data->group = 0;
	data->nb_eat_group = 0;
	data->nb_eat_count = 0;
	pthread_mutex_init(&data->nb_eat_group_m, NULL);
	pthread_mutex_init(&data->print_m, NULL);
	pthread_mutex_lock(&data->p_isdie_m);
	ft_routine(data);
	pthread_mutex_unlock(&data->p_isdie_m);
	ft_stop_simulation(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	if (ac < 5 || ac > 6)
	{
		printf("\e[0;31mWrong Number of arguments\e[0;m\n");
		return (0);
	}
	if (ft_parsing(ac, av, &data))
		return (0);
	if (!data.nb_philo)
	{
		printf("Nothing Philosophe : Aborting\n");
		return (0);
	}
	data.p_isdie = 1;
	error = ft_init_programme(&data);
	if (!error)
		ft_start_simulation(&data);
	if (error == -1)
		printf("\e[0;31mErreur : thread creation\e[0;m\n");
	if (error == -2)
		printf("\e[0;31mErreur : Malloc\e[0;m\n");
	return (0);
}
