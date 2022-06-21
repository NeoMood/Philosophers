/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:18:05 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:36:27 by sgmira           ###   ########.fr       */
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

void	*chkdeath(void *args)
{
	t_phparams	*p_data;
	t_args		*argph;

	p_data = (t_phparams *) args;
	argph = p_data->args;
	while (1)
	{
		if (p_data->eat_times >= p_data->args->timesofeat && argph->ac == 6)
			exit(1);
		if (argph->time2die < ft_time() - (p_data->lst_time_eaten))
		{
			sem_wait(argph->write);
			printf("%lld  %d died\n",
				ft_time() - (p_data->lst_time_eaten), p_data->p_id);
			exit(0);
		}
		usleep(1000);
	}
	return (NULL);
}
