/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:19:54 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/10 15:50:22 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_running(void *philo)
{
	t_philo	*ph;
	t_rule	*rule;

	ph = (t_philo *)philo;
	rule = ph->rule;
	if (ph->i % 2)
		usleep(1000 * 10);
	while (rule->alive && rule->all_eat)
	{
		if (ph->fork_l == ph->fork_r)
			break ;
		take_fork(rule, ph);
		eat(rule, ph);
		if (rule->alive == 0 || rule->all_eat == 0)
			break ;
		sleeping(rule, ph);
		print(rule, "is thinking", ph->i);
	}
	return (0);
}

int	init_thread(t_rule *rule)
{
	int	i;
	int	j;

	i = 0;
	while (i < rule->head)
	{
		if (pthread_create(&(rule->philo[i].thread), NULL,
				thread_running, &(rule->philo[i])))
		{
			j = 0;
			while (j < i)
			{
				pthread_join(rule->philo[j].thread, NULL);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (argc < 5 || 6 < argc)
		return (error("Error : argc count\n"));
	if (init_rule(&rule, argv))
		return (error("Error : input value\n"));
	if (init_malloc(&rule))
		return (error("Error : malloc\n"));
	init_philo(&rule);
	if (init_mutex(&rule))
		return (error("Error : mutex init\n"));
	if (init_thread(&rule))
		return (error("Error : thread init\n"));
	check_die(&rule, rule.philo);
	free_all(&rule);
	return (0);
}
