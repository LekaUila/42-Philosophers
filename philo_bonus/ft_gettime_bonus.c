/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:08 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/28 12:41:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long int	ft_gettime(t_time timep)
{
	t_time				time;
	unsigned long int	pr_time;
	unsigned long int	pr_time_bis;

	gettimeofday(&time, NULL);
	pr_time_bis = ((time.tv_usec - timep.tv_usec) / 1000);
	pr_time = ((time.tv_sec - timep.tv_sec) * 1000) + pr_time_bis;
	return (pr_time);
}
/*
Formule 1 :
((time.tv_sec * 1000) + (time.tv_usec / 1000)) 
- 
((timep.tv_sec * 1000) + (timep.tv_usec / 1000))
Formule 2 :
((time.tv_sec - timep.tv_sec) * 1000) + ((time.tv_usec - timep.tv_usec) / 1000)

*/