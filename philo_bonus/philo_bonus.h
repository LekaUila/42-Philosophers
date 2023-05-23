/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:07 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/04 11:02:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <signal.h>
# include <sys/wait.h>

typedef struct timeval		t_time;

typedef struct s_threadp	t_threadp;

typedef struct s_data
{
	t_threadp		*table;
	sem_t			*fork;
	int				nb_philo;
	sem_t			*reset;
	sem_t			*start;
	sem_t			*can_take;
	sem_t			*print_m;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				nb_eat;
	pthread_t		death_checker;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				nb;
	int				nb_eat;
	int				nb_nead_eat;
	unsigned long	last_eat;
	int				group;
	int				time_eat;
	unsigned long	time_die;
	int				time_sleep;
	sem_t			*start;
	sem_t			*print_m;
	sem_t			*can_take;
	sem_t			*reset;
	sem_t			*fork;
	t_time			start_time;
}	t_philo;

typedef struct s_threadp
{
	t_data			*data;
	int				nb;
	pthread_t		id;
	pid_t			pid;
	int				group;
	int				nb_nead_eat;
}	t_threadp;

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
void				ft_p_gothink_spe(t_philo *philo);
void				ft_i_am_alive(t_philo *philo);
int					ft_get_group(t_philo *philo);

/*Untils*/
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_error(char *error_msg);
void				*ft_check_death(void *datatemp);
void				ft_init_sem_m(t_data *data);

/*Free and cie*/
void				ft_close_sem_m(t_data *data);
void				ft_close_sem_p(t_philo *philo);
void				ft_stop_simulation(t_data *data);
void				ft_kill_philo(t_data *data);

#endif 