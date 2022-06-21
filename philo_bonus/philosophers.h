/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:48:08 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:36:40 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define  PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct args
{
	int				philo_num;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				timesofeat;
	int				timestamp;
	int				ac;
	struct phparams	*philo;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*eat;
	int				death;
}	t_args;

typedef struct phparams
{
	int			p_id;
	long long	lst_time_eaten;
	int			left_fork;
	int			right_fork;
	int			eat_times;
	pthread_t	philo_death;
	t_args		*args;
	pid_t		pro_ph;
}	t_phparams;

typedef struct getnum
{
	int		i;
	int		j;
	char	**tab;
	char	*joined;
}	t_getnum;

long		ft_atoi(const char *str);
long long	ft_time(void);
int			check_death(long long lst_time, int time2die, int id);
char		*get_numbers(char	**av);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strchr(const char *str, char c);
void		free_tab(char **tab);
int			ft_strlen(const char *str);
void		w_ph(t_args *args, int id, char *status, long long time);
void		ft_putstr(char *s);
int			arg_check(t_args	*args, int ac);
void		free_all(t_args *args, pthread_t *th);
void		destroy_forks(t_args *args);
void		*chkdeath(void *args);
void		my_sleep(long long duration, int timeto);
int			alloc_memory(t_args	*args);
void		init_params(t_args *args);
t_args		init_args(int ac, char **av);
void		init_forks(t_args *args);
char		**fill_tab(char	**av);
int			init_n_check(t_args	*args, int ac);
void		kill_all(t_args *args);

#endif