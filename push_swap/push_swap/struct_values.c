/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:17:12 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/08 16:01:47 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int arr_size)
{
	int i;
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

int find_pos(int *sorted, int arr_size, int value)
{
	int i;

	i = 0;
	while (i < arr_size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	} 
	return (-1);
}

void	determin_index(t_data *s, char sign)
{
	if (!sign)
		return ;
	if (sign == 'a')
		index_a(s);
	if (sign == 'b')
		index_b(s);
}

void index_a(t_data *s)
{
	int	*sorted;
	t_stack *temp;
	int i;

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

void index_b(t_data *s)
{
	int	*sorted;
	t_stack *temp;
	int i;

	sorted = malloc(sizeof(int) * s->b_size);
	temp = s->b;
	i = 0;
	while (i < s->b_size)
	{
		sorted[i] = temp->value;
		temp = temp->next;
		i++;
	}
	sort_array(sorted, s->b_size);
	temp = s->b;
	i = 0;
	while (i < s->b_size)
	{
		temp->index = find_pos(sorted, s->b_size, temp->value);
		temp = temp->next;
		i++;
	}
	free(sorted);
}
