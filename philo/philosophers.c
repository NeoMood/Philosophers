/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:05:44 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/18 23:19:55 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phparams	*p_data, long long fstmp)
{
	pthread_mutex_lock(&(p_data->args->mutex[p_data->right_fork]));
	w_ph(p_data->args, p_data->p_id, "has taken a fork",
		ft_time() - fstmp);
	pthread_mutex_lock(&(p_data->args->mutex[p_data->left_fork]));
	w_ph(p_data->args, p_data->p_id, "has taken a fork",
		ft_time() - fstmp);
	w_ph(p_data->args, p_data->p_id, "is eating",
		ft_time() - fstmp);
	(p_data->eat_times)++;
	if (check_eattimes(p_data))
		(p_data->args->allphiloeat)++;
	p_data->lst_time_eaten = ft_time();
}

void	*routine(void *args)
{
	t_phparams	*p_data;
	long long	ftime;
	long long	fstmp;

	p_data = (t_phparams *) args;
	if (p_data->p_id % 2 == 0)
		usleep(1000);
	fstmp = ft_time();
	while (1)
	{
		eat(p_data, fstmp);
		ftime = ft_time();
		my_sleep(ftime, p_data->args->time2eat);
		pthread_mutex_unlock(&(p_data->args->mutex[p_data->right_fork]));
		w_ph(p_data->args, p_data->p_id, "puts down a fork", ft_time() - fstmp);
		pthread_mutex_unlock(&(p_data->args->mutex[p_data->left_fork]));
		w_ph(p_data->args, p_data->p_id, "puts down a fork", ft_time() - fstmp);
		w_ph(p_data->args, p_data->p_id, "is sleeping", ft_time() - fstmp);
		ftime = ft_time();
		my_sleep(ftime, p_data->args->time2sleep);
		w_ph(p_data->args, p_data->p_id, "is thinking", ft_time() - fstmp);
	}
	return (NULL);
}

void	philo_launcher(t_args	*args, pthread_t	*th)
{
	int	i;

	i = 0;
	if (args->philo_num > 0)
	{
		while (i < args->philo_num)
		{
			pthread_create(&th[i], NULL, &routine, &args->philo[i]);
			if (args->philo_num == 1)
				my_sleep(ft_time(), args->time2die);
			i++;
		}
		if (chkdeath(args->philo, args))
		{
			destroy_forks(args);
			free_all(args, th);
		}
	}
}

int	main(int ac, char **av)
{
	char		**argstab;
	t_args		*args;
	pthread_t	*th;

	if (ac == 5 || ac == 6)
	{
		argstab = fill_tab(av);
		args = malloc(sizeof(t_args));
		if (!args)
			return (0);
		*args = init_args(ac, argstab);
		free_tab(argstab);
		th = malloc(sizeof(pthread_t *) * args->philo_num);
		if (!th)
			return (0);
		if (!alloc_memory(args))
			return (0);
		if (!init_n_check(args, ac))
			return (0);
		philo_launcher(args, th);
	}
	else
		printf("Error: Not enough arguments\n");
	return (0);
}
