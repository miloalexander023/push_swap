/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_number_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:18:48 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/09 21:48:54 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_target_b(t_data *s, t_stack *temp_b)
{
	t_stack	*temp_a;
	int		target;
	int		j;

	temp_a = s->a;
	target = temp_a->value;
	j = 0;
	while (j != s->a_size)
	{
		if (temp_b->value < temp_a->value
			&& temp_b->value > temp_a->prev->value)
			target = temp_a->value;
		if (temp_b->value < temp_a->value && temp_a->value < target)
		{
			target = temp_a->value;
			break ;
		}
		temp_a = temp_a->next;
		j++;
	}
	return (target);
}

void	find_targetnumber_b(t_data *s)
{
	t_stack	*temp_b;
	int		i;

	i = 0;
	if (!s || !s->a || s->b_size == 0)
		return ;
	temp_b = s->b;
	while (i < s->b_size)
	{
		temp_b->target = check_target_b(s, temp_b);
		temp_b = temp_b->next;
		i++;
	}
}
