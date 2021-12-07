/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:27:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/07 16:36:45 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_rule *rule, char *str, int i)
{
	if (rule->alive)
	{
		pthread_mutex_lock(&(rule->print));
		printf("%lld %d ", get_time() - rule->st_time, i + 1); //어차피 create 하기전에 한번만 시간 따놓으면됨
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
		usleep(50); // 필요할까? 어차피 스레드별로 해당 while을 계속 돌며 임계점을 넘는순간 정지시키는데?
		// 딜레이없이 계속해서 시간을 가져오면 과부하가 걸린다?
	}
	ph->eat++;

}
