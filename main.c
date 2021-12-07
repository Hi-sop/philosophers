/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:19:54 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/07 14:27:35 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_running(void *ph)
{
	t_rule	*rule;

	if (ph->i % 2)
		usleep(1000 * 10); // 10ms
	while 
}

int	init_thread(t_rule *rule)
{
	int	i;
	int	j;

	i = 0;
	while (i < rule->head)
	{
		if (pthread_create(&(rule->philo[i].thread_id), NULL,
					thread_running, &(rule->philo[i])))
		{
			j = 0;
			while (j < i)
			{
				pthread_join(rule->philo[j].thread_id, NULL);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_rule	rule;
	
	if (5 < argc || argc < 6)
		return (error("Error : argc count\n"));
	if (init_rule(&rule, argv))
		return (error("Error : input value\n"));
	if (init_malloc(rule))
		return (error("Error : malloc\n"));	
	init_philo(rule);
	if (init_mutex(rule))
		return (error("Error : mutex init\n"));
	if (init_thread(rule))
		return (error("Error : thread init\n"));
	
	//다잉체크
	//전체 join / free

	return (0);	
}
