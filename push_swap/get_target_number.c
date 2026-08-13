/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:18:48 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/13 22:28:20 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_targetnumber(t_data *s)
{
	t_stack *temp1;
	t_stack *temp2;

	temp1 = s->a;
	temp2 = s->b;
	if (!s || !s->b || s->a_size == 0)
		return ;
	target_loop(s, temp1, temp2);
}

void	target_loop(t_data *s, t_stack *temp1, t_stack *temp2)
{
	int target;
	int	i;
	int	j;

	i = 0;
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

void	rotation_cost(t_data *s)
{
	if (!s || !s->a || !s->b)
		return ;
	r_cost_a(s);
	r_cost_b(s);
}

void	r_cost_a(t_data *s)
{
	t_stack *temp;
	int	i;

	temp = s->a;
	i = 0;
	while(i < s->a_size)
	{
		if(temp->pos <= s->a_size / 2)
			temp->cost = temp->pos;
		else
			temp->cost = -1 * (s->a_size - temp->pos);
		temp = temp->next;
		i++;
	}
}

void	r_cost_b(t_data *s)
{
	t_stack *temp;
	int	i;

	temp = s->b;
	i = 0;
	while(i < s->b_size)
	{
		if(temp->pos <= s->b_size / 2)
			temp->cost = temp->pos;
		else
			temp->cost = -1 * (s->b_size - temp->pos);
		temp = temp->next;
		i++;
	}
}
// void	find_cost(t_data *s)
// {
// 	t_stack *temp1;
// 	t_stack *temp2;

// 	temp1 = s->a;
// 	temp2 = s->b;
	
// }