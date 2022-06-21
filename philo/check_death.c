/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:18:05 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:42:27 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_time(void)
{
	struct timeval	tv;
	long long		curtime;

	gettimeofday(&tv, NULL);
	curtime = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	return (curtime);
}

int	check_eattimes(t_phparams *p_data)
{
	if (p_data->eat_times >= p_data->args->timesofeat)
		return (1);
	return (0);
}

int	chkdeath(t_phparams *p_data, t_args *args)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < args->philo_num)
		{
			if (args->allphiloeat >= args->philo_num && args->ac == 6)
				return (1);
			else if (args->time2die < ft_time() - (p_data[i].lst_time_eaten))
			{
				pthread_mutex_lock(&args->write);
				printf("%lld  %d died\n", ft_time() - (p_data[i].lst_time_eaten),
					p_data[i].p_id);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
