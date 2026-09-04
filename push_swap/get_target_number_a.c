/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_number_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:18:48 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/04 18:39:53 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_target_a(t_data *s, t_stack *temp_a)
{
	t_stack	*temp_b;
	int		target;
	int		j;

	temp_b = s->b;
	target = temp_b->value;
	j = 0;
	while (j < s->b_size)
	{
		if (temp_a->value > temp_b->value
			&& temp_a->value < temp_b->prev->value)
			target = temp_b->value;
		if (temp_a->value > temp_b->value && temp_b->value > target)
		{
			target = temp_b->value;
			break ;
		}
		temp_b = temp_b->next;
		j++;
	}
	// printf("a_value: %d,   target_nbr: %d\n", temp_a->value, target);
	return (target);
}

void	target_loop_a(t_data *s, t_stack *temp_a)
{
	int	i;

	i = 0;
	while (i < s->a_size)
	{
		temp_a->target = check_target_a(s, temp_a);
		temp_a = temp_a->next;
		i++;
	}
}

void	find_targetnumber_a(t_data *s)
{
	t_stack	*temp_a;

	if (!s || !s->b || s->a_size == 0)
		return ;
	temp_a = s->a;
	target_loop_a(s, temp_a);
}
