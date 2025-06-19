/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_inict_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:06:51 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/19 12:12:40 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (c >= '\t' && c <= '\f')
		return (1);
	return (0)
}


long	ft_atol(char *str)
{
	int		i;
	long	num;
	int		sing;

	i = 0;
	num = 0;
	sing = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
	}

}
