/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:23:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/28 12:41:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_checker(char *to_convert, int *to_insert, char *string)
{
	if (ft_atoiwo(to_convert, to_insert))
	{
		printf("\e[0;31m%s : ❌\e[0;m\n", string);
		return (-1);
	}
	printf("\e[0;32m%s : ✅\e[0;m\n", string);
	return (0);
}

int	ft_parsing(int ac, char **av, t_data *data)
{
	int		error;
	char	*str;

	printf("\e[0;36m ⋋   CHECKING ARGUMENTS   ⋌ \e[0;m\n");
	str = "number_of_times_each_philosopher_must_eat";
	error = 0;
	error += ft_checker(av[1], &(data->nb_philo), "number_of_philosopher");
	error += ft_checker(av[2], &(data->time_die), "time_to_die");
	error += ft_checker(av[3], &(data->time_eat), "time_to_eat");
	error += ft_checker(av[4], &(data->time_sleep), "time_to_sleep");
	if (ac == 6)
		error += ft_checker(av[5], &(data->nb_eat), str);
	else
		data->nb_eat = -1;
	if (error)
	{
		printf("\e[0;31mError : Bad Arguments\e[0;m\n");
		printf("\e[0;36m ⋋ END CHECKING ARGUMENTS ⋌ \e[0;m\n");
		return (-1);
	}
	printf("\e[0;32mParsing : Good Arguments\e[0;m\n");
	printf("\e[0;36m ⋋ END CHECKING ARGUMENTS ⋌ \e[0;m\n");
	return (0);
}
