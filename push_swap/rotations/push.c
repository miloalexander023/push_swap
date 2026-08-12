/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:55:36 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/06 14:59:32 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data *pa(t_data *s)
{
	t_stack	*first;
	
	if (!s->b)
		return (s);
	first = s->b;
	if (first->next == first)
		s->b = NULL;
	else
	{
		first->next = s->a;
		first->prev = s->a->prev;
		first->next->prev = first;
	}
	if(!s->a)
	{
		first->next = first;
		first->prev = first;
		s->a = first;
	}
	else
	{
		first->next = s->a;
		first->prev = s->a->prev;
		s->a->prev->next = first;
		s->a->next->prev = first;
		s->a = first;
	}
	s->b_size--;
	s->a_size++;
	printf("pa\n");
	return (s);
}

t_data *pb(t_data *s)
{
	t_stack *first;

	if (!s->a)
		return (s);
	first = s->a;
	if (first->next == first)
		s->a = NULL;
	else
	{
		s->a = first->next;
		s->a->prev = first->prev;
		first->prev->next = s->a;
	}
	if (!s->b)
	{
		first->next = first;
		first->prev = first;
		s->b = first;
	}
	else
	{
		first->next = s->b;
		first->prev = s->b->prev;
		s->b->prev->next = first;
		s->b->prev = first;
		s->b = first;
	}
	s->a_size--;
	s->b_size++;
	printf("pb\n");
	return (s);
}