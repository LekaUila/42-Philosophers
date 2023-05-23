/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:00:13 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/02 11:58:41 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *error_msg)
{
	int	i;

	i = 0;
	while (error_msg[i])
	{
		write(2, error_msg + i, 1);
		i++;
	}
	exit(EXIT_FAILURE);
}
