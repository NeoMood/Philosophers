/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:05:01 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/18 23:22:03 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	w_ph(t_args *args, int id, char *status, long long time)
{
	pthread_mutex_lock(&args->write);
	printf("%lld  ", time);
	printf("%i ", id);
	printf("%s\n", status);
	pthread_mutex_unlock(&args->write);
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
