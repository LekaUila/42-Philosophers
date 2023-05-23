/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_activity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:27 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 15:35:45 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	ft_print_activity(t_philo *philo, char *activity)
{
	unsigned long int	pr_time;

	pr_time = ft_gettime(philo->start_time);
	pthread_mutex_lock(&philo->data->print_m);
	printf("%lu %i %s\n", pr_time, philo->nb, activity);
	pthread_mutex_unlock(&philo->data->print_m);
	return (pr_time);
}
