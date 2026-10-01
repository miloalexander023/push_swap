/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 23:36:24 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/17 20:20:56 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

int	check_dup(char **argv, int size)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			value_i = ft_atol_checked(argv[i]);
			value_j = ft_atol_checked(argv[j]);
			if (value_j == value_i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(char **argv, int argc)
{
	int	i;

	i = 1;
	if (!argv || argc < 2)
		return (0);
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	if (!check_dup(argv, argc))
		return (0);
	return (1);
}
