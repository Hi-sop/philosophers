/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/10 13:43:56 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	free_all(t_rule *rule)
{
	int	i;
	
	i = 0;
	while (i < rule->head)
	{
		pthread_join(rule->philo[i].thread, NULL);
		i++;
	}
	free(rule->philo);
	pthread_mutex_destroy(&rule->print);
	i = 0;
	while (i < rule->head)
	{
		pthread_mutex_destroy(&(rule->forks[i]));
		i++;
	}
	free(rule->forks);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i])
	{
		if (!((9 <= str[i] && str[i] <= 13) || ('0' <= str[i] && str[i] <= '9')
				|| str[i] == ' '))
				return (-1);
		i++;
	}
	i = 0;
	num = 0;
	while (str[i] && ((9 <= str[i] && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
