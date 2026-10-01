/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 21:05:15 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/17 20:29:05 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_cost(t_data *s)
{
	if (!s || !s->a || !s->b)
		return ;
	r_cost_a(s);
	r_cost_b(s);
}

void	r_cost_a(t_data *s)
{
	t_stack	*temp;
	int		i;

	temp = s->a;
	i = 0;
	while (i < s->a_size)
	{
		if (temp->pos <= s->a_size / 2)
			temp->cost = temp->pos;
		else
			temp->cost = -(s->a_size - temp->pos);
		temp = temp->next;
		i++;
	}
}

void	r_cost_b(t_data *s)
{
	t_stack	*temp;
	int		i;

	temp = s->b;
	i = 0;
	while (i < s->b_size)
	{
		if (temp->pos <= s->b_size / 2)
			temp->cost = temp->pos;
		else
			temp->cost = -(s->b_size - temp->pos);
		temp = temp->next;
		i++;
	}
}

void	final_rotations(t_data *s)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		i;
	int		pos;

	update_pos(s, 'a');
	smallest = s->a;
	temp = s->a->next;
	i = 0;
	while (i < s->a_size)
	{
		if (temp->value < smallest->value)
			smallest = temp;
		temp = temp->next;
		i++;
	}
	pos = smallest->pos;
	rotate_a_to_pos(s, pos);
}
