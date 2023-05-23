/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:36:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 15:54:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_nb_eat(t_data *data)
{
	int	nb_need;

	if (data->nb_philo % 2 == 0)
	{
		if (data->nb_eat_group >= data->nb_philo / 2)
			return (1);
		return (0);
	}
	nb_need = data->nb_philo / 3;
	if (data->group == 1)
		nb_need = nb_need + (data->nb_philo % 3 == 2);
	else if (data->group == 2)
		nb_need = nb_need + (data->nb_philo % 3 > 0);
	if (data->nb_eat_group >= nb_need)
		return (1);
	return (0);
}
