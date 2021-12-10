/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:51:51 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:29 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_rule *rule)
{
	int	i;
	int	j;

	if (pthread_mutex_init(&(rule->print), NULL))
		return (1);
	i = 0;
	while (i < rule->head)
	{
		if (pthread_mutex_init(&(rule->forks[i]), NULL))
		{
			pthread_mutex_destroy(&(rule->print));
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&(rule->forks[j]));
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_philo(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->head)
	{
		rule->philo[i].i = i;
		rule->philo[i].fork_l = i;
		rule->philo[i].fork_r = (i + 1) % rule->head;
		rule->philo[i].eat = 0;
		rule->philo[i].time = get_time();
		rule->philo[i].rule = rule;
		i++;
	}
}

int	init_malloc(t_rule *rule)
{
	rule->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * rule->head);
	if (!(rule->forks))
		return (1);
	rule->philo = (t_philo *)malloc(sizeof(t_philo) * rule->head);
	if (!(rule->philo))
	{
		free(rule->forks);
		return (1);
	}
	return (0);
}

int	init_rule(t_rule *rule, char **argv)
{
	rule->head = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	if (rule->head < 1 || rule->t_die < 1
			|| rule->t_eat == -1 || rule->t_sleep == -1)
		return (1);
	if (argv[5])
		rule->c_eat = ft_atoi(argv[5]);
	else
		rule->c_eat = -1;
	rule->st_time = get_time();
	rule->alive = 1;
	rule->all_eat = rule->head;
	return (0);
}

