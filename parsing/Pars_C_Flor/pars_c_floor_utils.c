/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_floor_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:12:05 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/07 17:13:23 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pars_cub3d.h"

int	ft_count_specific_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

bool	ft_atoi_if(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result > 255)
			return (false);
		nptr++;
	}
	return (true);
}
