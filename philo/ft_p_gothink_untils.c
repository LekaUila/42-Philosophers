/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_gothink_untils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:19:34 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 16:06:06 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_group(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->data->nb_eat_group_m);
	ret = philo->data->group;
	pthread_mutex_unlock(&philo->data->nb_eat_group_m);
	return (ret);
}
