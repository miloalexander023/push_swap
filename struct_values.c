/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:17:12 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/11 15:58:17 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < arr_size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	find_pos(int *sorted, int arr_size, int value)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	determin_index(t_data *s)
{
	t_stack	*temp;
	int		*sorted;
	int		i;

	sorted = malloc(sizeof(int) * s->a_size);
	temp = s->a;
	i = 0;
	while (i < s->a_size)
	{
		sorted[i] = temp->value;
		temp = temp->next;
		i++;
	}
	sort_array(sorted, s->a_size);
	temp = s->a;
	i = 0;
	while (i < s->a_size)
	{
		temp->index = find_pos(sorted, s->a_size, temp->value);
		temp = temp->next;
		i++;
	}
	free(sorted);
}
