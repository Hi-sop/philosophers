/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:51:51 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/06 19:18:34 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	init_philo(t_rule *rule)
{
	int	i;

	i = 0;
	rule->philo = (t_philo *)malloc(sizeof(t_philo) * rule->head);
	if (!(rule->philo))
		return (1);
	while (i < rule->head)
	{
		
	}
	reutnr (0);
}

int	init_forks(t_rule *rule)
{
	int				i;
	
	rule->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * rule->head);
	if (!(rule->forks))
		return (1);
	i = 0;
	while (i < rule->head)
	{
		if (pthread_mutex_init(&(rule->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(rule->print), NULL))
		return (1);
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
	rule->philo = NULL;
	rule->st_time = get_time();
	rule->die = 0;
	//all eat이 들어갈 자리이나 없어도 구현이 가능할것같음. 추후수정
	if (init_forks(rule) || init_philo(rule))
		return (1);
	return (0);
}

