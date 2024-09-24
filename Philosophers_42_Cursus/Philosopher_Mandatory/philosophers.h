/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:27:24 by abait-ou          #+#    #+#             */
/*   Updated: 2024/09/12 11:44:14 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <limits.h>



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
    pthread_t philosopher;
    t_fork    *first_fork;
    t_fork    *seconde_fork;
    long      meals_number;
    int       flag_full_or_not;
    t_table   *table;
}              t_philosopher;


struct s_table
{
    long    number_of_philos;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meals_left;
    long    start_simulation;
    int     flag_end_simulation;
    t_fork        *forks;
    t_philosopher *philos;
};

enum s_enum
{
  LOCK,
  UNLOCK,
  INIT,
  DESTROY,
  DETACH,
  DESTROY  
};


// Parsing Prototypes Functions

void       ft_parsinput(t_table *table, char **argv);


// Error Handling Pototypes Functions

void        ft_caseexite01();


// Outils  Prototypes  Functions

int         ft_isspace(char c);
int         ft_isdigit(char c);
long long	ft_atol(const char *str);