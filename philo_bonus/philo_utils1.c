/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:05:01 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/19 20:37:49 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	w_ph(t_args *args, int id, char *status, long long time)
{
	sem_wait(args->write);
	printf("%lld  ", time);
	printf("%i ", id);
	printf("%s\n", status);
	sem_post(args->write);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	result;

	result = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] > '9' || str[i] < '0'))
		return (-1);
	result *= s;
	return (result);
}

void	kill_all(t_args *args)
{
	int	i;
	int	stat;
	int	a;

	a = waitpid(-1, &stat, 0);
	if (stat == 0)
	{
		i = -1;
		while (++i < args->philo_num)
		{
			if (args->philo[i].pro_ph == a)
				i++;
			kill(args->philo[i].pro_ph, SIGKILL);
		}
	}
	else
	{
		i = 0;
		while (++i < args->philo_num)
			waitpid(-1, NULL, 0);
	}
	sem_close(args->forks);
	sem_unlink("/fork");
	sem_unlink("/write");
	exit(0);
}
