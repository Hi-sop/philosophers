/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:59:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/10 16:16:57 by khee-seo         ###   ########.fr       */
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
	int				i;
	int				fork_l;
	int				fork_r;
	int				eat;
	long long		time;
	pthread_t		thread;
	struct s_rule	*rule;
}					t_philo;

typedef struct s_rule
{
	int				head;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				c_eat;
	t_philo			*philo;
	long long		st_time;
	int				alive;
	int				all_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}					t_rule;

int			init_mutex(t_rule *rule);
void		init_philo(t_rule *rule);
int			init_malloc(t_rule *rule);
int			init_rule(t_rule *rule, char **argv);

int			error(char *arr);
void		free_all(t_rule *rule);
long long	get_time(void);
int			ft_atoi(char *str);

void		print(t_rule *rule, char *str, int i);
void		take_fork(t_rule *rule, t_philo *ph);
void		eat(t_rule *rule, t_philo *ph);
void		sleeping(t_rule *rule, t_philo *ph);
void		check_die(t_rule *rule, t_philo *ph);

#endif
