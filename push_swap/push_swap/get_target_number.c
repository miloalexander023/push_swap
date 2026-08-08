/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:18:48 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/08 17:41:53 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_targetnumber(t_data *s)
{
	t_stack *temp1;
	t_stack *temp2;
	int target;
	int i;
	int j;

	temp1 = s->a;
	temp2 = s->b;
	i = 0;
	if (!s || !s->b || s->a_size == 0)
		return ;
	while (i < s->a_size)
	{
		target = temp2->value;
		j = 0;
		while (j < s->b_size)
		{
			if (temp1->value > temp2->value && temp1->value < temp2->prev->value)
				target = temp2->value;
			if (temp1->value > temp2->value && temp2->value > target)
			{
				target = temp2->value;
				break ;
			}
			temp2 = temp2->next;
			j++;
		}
		temp1->target = target;
		temp1 = temp1->next;
		temp2 = s->b;
		i++;
	}
}

