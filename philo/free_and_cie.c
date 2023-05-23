/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:10:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 16:46:32 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_fork(int nb, pthread_mutex_t *fork)
{
	while (nb != 0)
	{
		if (fork + nb != 0)
			pthread_mutex_destroy(fork + nb - 1);
		nb--;
	}
	free(fork);
}

void	ft_stop_simulation(t_data *data)
{
	int	ind;

	ind = 0;
	while (ind != data->nb_philo)
	{
		pthread_join(data->table[ind].id, NULL);
		ind++;
	}
	if (data->nb_eat != -1 && data->nb_eat == data->nb_eat_count)
	{
		printf("\e[0;32mles philo ont mangé %i fois\n\e[0;m", data->nb_eat);
	}
	pthread_mutex_destroy(&data->nb_eat_group_m);
	pthread_mutex_destroy(&data->p_isdie_m);
	ft_destroy_fork(data->nb_philo, data->fork);
	free(data->table);
}
