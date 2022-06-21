/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:48:28 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 00:21:06 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_args *args, pthread_t *th)
{
	free(args->philo);
	free(args->forks);
	free(args->write);
	free(args->eat);
	free(th);
}

void	my_sleep(long long duration, int timeto)
{
	while (1)
	{
		if ((ft_time() - duration) >= timeto)
			break ;
		usleep(50);
	}
}

int	alloc_memory(t_args	*args)
{
	args->philo = malloc(sizeof(t_phparams) * args->philo_num);
	if (!args->philo)
		return (0);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
