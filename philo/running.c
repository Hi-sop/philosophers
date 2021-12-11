/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:27:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/11 12:40:16 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_rule *rule, char *str, int i)
{
	if (rule->alive)
	{
		pthread_mutex_lock(&(rule->print));
		printf("%lld %d ", get_time() - rule->st_time, i + 1);
		printf("%s\n", str);
		pthread_mutex_unlock(&(rule->print));
	}
}

void	take_fork(t_rule *rule, t_philo *ph)
{
	pthread_mutex_lock(&(rule->forks[ph->fork_l]));
	print(rule, "has taken a fork", ph->i);
	pthread_mutex_lock(&(rule->forks[ph->fork_r]));
	print(rule, "has taken a fork", ph->i);
}

void	eat(t_rule *rule, t_philo *ph)
{
	print(rule, "is eating", ph->i);
	ph->time = get_time();
	while (rule->alive)
	{
		if (rule->t_eat <= get_time() - ph->time)
			break ;
		usleep(50);
	}
	ph->eat = ph->eat + 1;
	if (ph->eat == rule->c_eat)
		rule->all_eat = rule->all_eat - 1;
	pthread_mutex_unlock(&(rule->forks[ph->fork_l]));
	pthread_mutex_unlock(&(rule->forks[ph->fork_r]));
}

void	sleeping(t_rule *rule, t_philo *ph)
{
	long long	st;

	print(rule, "is sleeping", ph->i);
	st = get_time();
	while (rule->alive)
	{
		if ((get_time() - st) >= rule->t_sleep)
			break ;
		usleep(50);
	}
}

void	check_die(t_rule *rule, t_philo *ph)
{
	int	i;

	while (rule->alive && rule->all_eat != 0)
	{
		i = 0;
		while (i < rule->head && rule->all_eat != 0)
		{
			if (get_time() - ph[i].time > rule->t_die)
			{
				print(rule, "died", ph[i].i);
				rule->alive = 0;
			}
			i++;
			usleep(50);
		}
	}
}
