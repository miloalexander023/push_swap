/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:42:26 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/24 16:20:23 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"

void	printlist(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return ;
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
		if (temp == head)
			break ;
	}
}

int	check_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+')
		sign = 1;
	return (sign);
}

long	ft_atol_checked(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = check_sign(str);
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
	return (result * sign);
}

int	is_sorted(t_data *s)
{
	t_stack	*temp;

	temp = s->a;
	if (!s)
		return (0);
	while (temp->next->value != s->a->value)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc == 1 || argc == 2)
		return (1);
	data.a = NULL;
	data.b = NULL;
	data.a_size = 0;
	data.b_size = 0;
	data.moves = 0;
	fill_stack_a(&data, argv, argc);
	if (is_sorted(&data))
		return (printf("ALREADY SORTED!!!!\n"), 0);
	determin_index(&data);
	turk_sort(&data);
	printlist(data.a);
	if (!is_sorted(&data))
		printf("STILL NOT SORTED!!!!\n");
	else
		printf("SORTED!!!!\n");
	return (0);
}
