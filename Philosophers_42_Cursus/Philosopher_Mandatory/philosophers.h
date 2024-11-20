/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:27:24 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/20 15:43:45 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PHILO 200

typedef struct s_table	t_table;
typedef enum s_enum		t_status;

typedef struct s_fork
{
	int					fork_id;
	pthread_mutex_t		fork;
}						t_fork;

typedef struct s_philo
{
	int					philo_id;
	int					meals_eaten;
	long				last_meal;
	int					eating;
	int 				attach;
	t_table				*table;
	pthread_t			thread;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*seconde_fork;
	pthread_mutex_t		*death_lock;
	pthread_mutex_t		*eat_lock;
	pthread_mutex_t		*print_lock;
}						t_philo;

typedef struct s_table
{
	long				philos_number;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die;
	int					meals_number;
	long				start_simu;
	int					end_simu;
	int					dead;
	pthread_mutex_t		death;
	pthread_mutex_t		eat;
	pthread_mutex_t		print;
	t_philo				philos[MAX_PHILO];
	t_fork				forks[MAX_PHILO];
}						t_table;

// Init Funtcions Prototype

void					ft_parsinput(t_table *table, char **argv);

// Outils Functions Prototype

long long				ft_atol(const char *str);
int						ft_isdigit(char c);
int						ft_isspace(char c);
int						ft_usleep(size_t milliseconds, t_philo *philo);
size_t					get_time(void);
void					print_messag(long time, int id, char *str,
							t_philo *philo);
long long				ft_timestamp(t_table *table);

// Data Init (For Forks And Threads) Functios Prototype

void					ft_inittable(t_table *table);
void					ft_forksinit(t_table *table);
void					ft_philosinit(t_table *table);

// Dinner Simulation Functions Prototypes

void					ft_dinner(t_table *table);
void					*ft_routine(void *arg);
void					*ft_monitor(void *arg);
int						ft_deathcheck(t_philo *philo);
void					ft_mutexdestroy(t_table *table);
// Dinner Actions
int						ft_takeforks(t_philo *philo);
void					ft_releaseforks(t_philo *philo);
int						ft_sleep(t_philo *philo);
int						ft_think(t_philo *philo);
int						eat(t_philo *philo);
// Error Management Fucntions Prototypes

void					ft_caseexite01(void);
void 					diedexit(t_philo *philo);