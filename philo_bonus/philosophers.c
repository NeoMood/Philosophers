/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:05:44 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:41:06 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phparams	*p_data, long long fstmp, t_args *args)
{
	sem_wait(args->forks);
	w_ph(p_data->args, p_data->p_id, "has taken a fork", ft_time() - fstmp);
	sem_wait(args->forks);
	w_ph(p_data->args, p_data->p_id, "has taken a fork", ft_time() - fstmp);
	w_ph(p_data->args, p_data->p_id, "is eating", ft_time() - fstmp);
	p_data->lst_time_eaten = ft_time();
}

void	cond_sleep(int p_id)
{
	if (p_id % 2 == 0)
		usleep(1000);
}

void	routine(t_phparams *p_data)
{
	long long	ftime;
	long long	fstmp;
	t_args		*args;

	args = p_data->args;
	cond_sleep(p_data->p_id);
	fstmp = ft_time();
	pthread_create(&p_data->philo_death, NULL, chkdeath, p_data);
	while (1)
	{
		eat(p_data, fstmp, args);
		ftime = ft_time();
		my_sleep(ftime, p_data->args->time2eat);
		sem_post(args->forks);
		w_ph(p_data->args, p_data->p_id, "puts down a fork", ft_time() - fstmp);
		sem_post(args->forks);
		w_ph(p_data->args, p_data->p_id, "puts down a fork", ft_time() - fstmp);
		(p_data->eat_times)++;
		w_ph(p_data->args, p_data->p_id, "is sleeping", ft_time() - fstmp);
		ftime = ft_time();
		my_sleep(ftime, p_data->args->time2sleep);
		w_ph(p_data->args, p_data->p_id, "is thinking", ft_time() - fstmp);
	}
	pthread_join(p_data->philo_death, NULL);
	exit (0);
}

void	philo_launcher(t_args	*args)
{
	int	i;

	i = -1;
	if (args->philo_num > 0)
	{
		while (++i < args->philo_num)
		{
			args->philo[i].pro_ph = fork();
			if (args->philo[i].pro_ph < 0)
				return ;
			else if (args->philo[i].pro_ph == 0)
				routine(&args->philo[i]);
			if (args->philo_num == 1)
				my_sleep(ft_time(), args->time2die);
			usleep(50);
		}
		kill_all(args);
	}
}

int	main(int ac, char **av)
{
	char		**argstab;
	t_args		*args;

	if (ac == 5 || ac == 6)
	{
		argstab = fill_tab(av);
		args = malloc(sizeof(t_args));
		if (!args)
			return (0);
		*args = init_args(ac, argstab);
		free_tab(argstab);
		if (!alloc_memory(args))
			return (0);
		if (!init_n_check(args, ac))
			return (0);
		philo_launcher(args);
	}
	else
		printf("Error: Not enough arguments\n");
	return (0);
}
