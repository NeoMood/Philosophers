/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:21:38 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/18 23:22:19 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_getnum	space_case(char	**av, t_getnum	getnum)
{
	getnum.tab = ft_split(av[getnum.i], ' ');
	if (!*getnum.tab)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	getnum.j = 0;
	while (getnum.tab[getnum.j])
	{
		getnum.joined = ft_strjoin(getnum.joined, getnum.tab[getnum.j]);
		getnum.joined = ft_strjoin(getnum.joined, " ");
		getnum.j++;
	}
	free_tab(getnum.tab);
	return (getnum);
}

char	*get_numbers(char	**av)
{
	t_getnum	getnum;

	getnum.i = 1;
	getnum.j = 0;
	getnum.joined = malloc(1);
	getnum.joined[0] = '\0';
	while (av[getnum.i])
	{
		if (ft_strchr(av[getnum.i], ' '))
			getnum = space_case(av, getnum);
		else
		{
			getnum.joined = ft_strjoin(getnum.joined, av[getnum.i]);
			getnum.joined = ft_strjoin(getnum.joined, " ");
		}
		getnum.i++;
	}
	return (getnum.joined);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
