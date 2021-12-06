/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/12/06 15:35:39 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
