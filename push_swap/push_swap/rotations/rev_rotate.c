/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:21:23 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/06 15:45:51 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data *rra(t_data *s)
{
	t_stack *first;

	if (!s->a || s->a->next == s->a)
		return NULL;
	first = s->a;
	s->a->next->prev = first;
	first->prev = s->a->prev;
	first->next = s->a->next;
	s->a = s->a->prev;
	s->a->next = first;
	printf("rra\n");
	return (s);
}

t_data *rrb(t_data *s)
{
	t_stack *first;

	if (!s->b || s->b->next == s->b)
		return NULL;
	first = s->b;
	s->b->next->prev = first;
	first->prev = s->b->prev;
	first->next = s->b->next;
	s->b = s->b->prev;
	s->b->next = first;
	printf("rrb\n");
	return (s);
}

t_data *rrr(t_data *s)
{
	rra(s);
	rrb(s);
	return (s);
}