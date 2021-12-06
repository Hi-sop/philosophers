/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:59:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/06 16:27:22 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

struct				s_rule;

typedef struct s_philo
{
	int				index;
	int				fork_l;
	int				fork_r;
	int				eat;
	long long		time;
	pthread_t		thread;
	struct s_rule	*rule;
	pthread_mutex_t	eating;
}					t_philo;

typedef struct	s_rule
{
	int				head;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				c_eat;
	t_philo			*philo;
	long long		st_time;
	int				die;
	int				all_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}					t_rule;

#endif

