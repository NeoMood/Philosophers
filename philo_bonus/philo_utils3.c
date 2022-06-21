/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:16:51 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:41:36 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_params(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		args->philo[i].args = args;
		args->philo[i].p_id = i + 1;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->philo_num;
		args->philo[i].lst_time_eaten = ft_time();
		args->philo->eat_times = 0;
		i++;
	}
}

t_args	init_args(int ac, char **av)
{
	t_args	args;

	args.philo_num = ft_atoi(av[0]);
	args.time2die = ft_atoi(av[1]);
	args.time2eat = ft_atoi(av[2]);
	args.time2sleep = ft_atoi(av[3]);
	if (ac == 6)
		args.timesofeat = ft_atoi(av[4]);
	args.ac = ac;
	return (args);
}

void	init_forks(t_args *args)
{
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_unlink("/eat");
	args->forks = sem_open("/fork", O_CREAT, S_IRWXU, args->philo_num);
	args->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	args->eat = sem_open("/eat", O_CREAT, S_IRWXU, 1);
}

char	**fill_tab(char	**av)
{
	char	**argstab;
	char	*tab;

	tab = get_numbers(av);
	argstab = ft_split(tab, ' ');
	free(tab);
	return (argstab);
}

int	init_n_check(t_args	*args, int ac)
{
	init_params(args);
	init_forks(args);
	if (arg_check(args, ac))
		return (0);
	return (1);
}
