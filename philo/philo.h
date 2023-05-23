/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:07 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 15:34:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_philo	t_philo;

typedef struct s_data
{
	t_philo			*table;
	pthread_mutex_t	*fork;
	int				nb_philo;
	pthread_mutex_t	p_isdie_m;
	int				p_isdie;
	pthread_mutex_t	print_m;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				group;
	pthread_mutex_t	nb_eat_group_m;
	int				nb_eat_group;
	int				nb_eat;
	int				nb_eat_count;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				nb;
	unsigned long	last_eat;
	pthread_t		id;
	int				group;
	int				time_eat;
	unsigned long	time_die;
	int				time_sleep;
	t_time			start_time;
}	t_philo;

/*Parsing*/
int					ft_atoiwo(const char *str, int *n);
int					ft_parsing(int ac, char **av, t_data *data);

/*Time function*/
unsigned long int	ft_gettime(t_time timep);

/*Philo*/
unsigned long int	ft_print_activity(t_philo *philo, char *activity);
void				*start_routine(void *datatemp);
void				ft_p_gosleep(t_philo *philo);
void				ft_p_goeat(t_philo *philo);
void				ft_p_gothink(t_philo *philo);
int					ft_i_am_alive(t_philo *philo);
void				ft_release_right_fork(t_philo *philo);
void				ft_release_left_fork(t_philo *philo);
int					ft_get_group(t_philo *philo);

/*Untils*/
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_check_nb_eat(t_data *data);

/*Free and cie*/
void				ft_destroy_fork(int nb, pthread_mutex_t *fork);
void				ft_stop_simulation(t_data *data);

#endif 