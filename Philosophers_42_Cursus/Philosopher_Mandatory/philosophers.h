/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:27:24 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 21:21:48 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include <sys/time.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#define MAX_PHILO 200



typedef struct s_table t_table;
typedef enum   s_enum  t_status;

typedef struct s_fork
{
    int fork_id;
    pthread_mutex_t fork;
}              t_fork;

typedef struct s_philosopher
{
    int       philo_id;
    pthread_t thread;
    t_fork    *first_fork;
    t_fork    *second_fork;
    long      meals_number;
    int       flag_full_or_not;
    long      last_meal;
    t_table   *table;
}              t_philosopher;


struct s_table
{
    long    number_of_philos;
    pthread_mutex_t print_mutex;
    int current_print_id;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meals_left;
    long    start_simulation;
    int     flag_end_simulation;
    int     ready_or_not;
    t_fork        forks[MAX_PHILO];
    t_philosopher philos[MAX_PHILO];
};

enum s_enum
{
  LOCK,
  UNLOCK,
  INIT,
  DETACH,
  DESTROY  
};


// Parsing Prototypes Functions

void       ft_parsinput(t_table *table, char **argv);


// Error Handling Pototypes Functions

void        ft_caseexite01();

// Init Members Functions Prototypes

void *ft_monitor(void *arg);
void ft_inittable(t_table *table, pthread_t *monitor);
void ft_initforks(t_table *table);
void ft_destroyforks(t_table *table);
void *ft_routine(void *arg);
void ft_threadjoin(t_table *table);


// Outils  Prototypes  Functions

int         ft_isspace(char c);
int         ft_isdigit(char c);
long long	ft_atol(const char *str);
long        ft_gettime(void);
void	    ft_usleep(long int time_to_wait);

// Dinner Simulation Functions

long int	get_time(void);