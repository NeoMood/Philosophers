/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:39:09 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/18 17:23:30 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *errmess)
{
	printf("Error: %s\n", errmess);
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	arg_check(t_args	*args, int ac)
{
	int	i;

	i = 0;
	if (args->philo_num <= 0 || args->philo_num > 2147483647)
		i = ft_error("philo number");
	if (args->time2die < 0 || args->time2die > 2147483647)
		i = ft_error("Time to die");
	if (args->time2eat < 0 || args->time2eat > 2147483647)
		i = ft_error("Time to eat");
	if (args->time2sleep < 0 || args->time2sleep > 2147483647)
		i = ft_error("Time to sleep");
	if (ac == 6)
	{
		if (args->timesofeat < 0 || args->timesofeat > 2147483647)
			i = ft_error("Eat times");
	}
	if (i == 0)
		return (0);
	else
		return (1);
}
