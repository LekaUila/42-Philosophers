/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_activity_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:27 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/03 15:58:48 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long int	ft_print_activity(t_philo *philo, char *activity)
{
	unsigned long int	pr_time;

	pr_time = ft_gettime(philo->start_time);
	sem_wait(philo->print_m);
	printf("%lu %i %s\n", pr_time, philo->nb, activity);
	sem_post(philo->print_m);
	return (pr_time);
}
