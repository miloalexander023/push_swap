/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 22:30:14 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/09 21:42:43 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_cost(int a_cost, int b_cost)
{
	int	r_cost;

	r_cost = INT_MAX;
	if (a_cost >= 0 && b_cost >= 0)
	{
		if (a_cost >= b_cost)
			r_cost = a_cost;
		else
			r_cost = b_cost;
	}
	if (a_cost >= 0 && b_cost < 0)
		r_cost = a_cost + (b_cost * -1);
	if (a_cost < 0 && b_cost >= 0)
		r_cost = b_cost + (a_cost * -1);
	if (a_cost < 0 && b_cost < 0)
	{
		if (a_cost <= b_cost)
			r_cost = a_cost * -1;
		else
			r_cost = b_cost * -1;
	}
	return (r_cost);
}

t_stack	*find_target(t_stack *b, int target)
{
	while (b->value != target)
		b = b->next;
	return (b);
}

t_stack	*cheapest(t_data *s)
{
	t_stack	*b;
	t_stack	*cheapest;
	int		r_cost;
	int		best_cost;
	int		i;

	r_cost = 0;
	best_cost = INT_MAX;
	cheapest = 0;
	i = 0;
	while (i != s->a_size)
	{
		b = find_target(s->b, s->a->target);
		r_cost = target_cost(s->a->cost, b->cost);
		if (r_cost < best_cost)
		{
			best_cost = r_cost;
			cheapest = s->a;
		}
		i++;
		s->a = s->a->next;
	}
	return (cheapest);
}
