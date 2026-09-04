/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:57:56 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/04 18:18:39 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*rotate_push(t_data *s, t_stack *push_nbr)
{
	t_stack	*b;

	if (push_nbr->value == 500)
		printf("push_nbr: %d,   target_nbr: %d\n", push_nbr->value, push_nbr->target);
	b = find_target(s->b, push_nbr->target);
	if (push_nbr->cost == 0 && b->cost == 0)
		pb(s);
	else if (push_nbr->cost >= 0 && b->cost >= 0)
	{
		positive_rotations(s, push_nbr->cost, b->cost);
		pb(s);
	}
	else if (push_nbr->cost <= -1 && b->cost <= -1)
	{
		negative_rotations(s, push_nbr->cost, b->cost);
		pb(s);
	}
	else if (push_nbr->cost <= -1 && b->cost >= 0)
	{
		a_negative_rotations(s, push_nbr->cost, b->cost);
		pb(s);
	}
	else if (b->cost <= -1 && push_nbr->cost >= 0)
	{
		b_negative_rotations(s, push_nbr->cost, b->cost);
		pb(s);
	}
	return (s);
}

void	positive_rotations(t_data *s, int a_cost, int b_cost)
{
	while (a_cost >= 1 && b_cost >= 1)
	{
		rr(s);
		a_cost--;
		b_cost--;
	}
	if (a_cost > b_cost)
	{
		while(a_cost >= 1)
		{
			ra(s);
			a_cost--;
		}
	}
	if (b_cost > a_cost)
	{
		while(b_cost >= 1)
		{
			rb(s);
			b_cost--;
		}
	}
}

void	negative_rotations(t_data *s, int a_cost, int b_cost)
{
	while (a_cost <= -1 && b_cost <= -1)
	{
		rrr(s);
		a_cost++;
		b_cost++;
	}
	if (a_cost < b_cost)
	{
		while(a_cost <= -1)
		{
			rra(s);
			a_cost++;
		}
	}
	if (b_cost < a_cost)
	{
		while(b_cost <= -1)
		{
			rrb(s);
			b_cost++;
		}
	}
}

void	a_negative_rotations(t_data *s, int a_cost, int b_cost)
{
	while (a_cost <= -1)
	{
		rra(s);
		a_cost++;
	}
	while (b_cost >= 1)
	{
		rb(s);
		b_cost--;
	}
}


void	b_negative_rotations(t_data *s, int a_cost, int b_cost)
{
	while (b_cost <= -1)
	{
		rrb(s);
		b_cost++;
	}
	while (a_cost >= 1)
	{
		ra(s);
		a_cost--;
	}	
}