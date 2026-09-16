/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:55:36 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/10 18:30:46 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../printf.h"

t_data	*pa(t_data *s)
{
	t_stack	*first;

	if (!s->b)
		return (s);
	first = s->b;
	if (first->next == first)
		s->b = NULL;
	else
	{
		s->b = first->next;
		first->prev->next = first->next;
		first->next->prev = first->prev;
	}
	fix_head_a(s->a, first);
	s->a = first;
	s->b_size--;
	s->a_size++;
	s->moves++;
	// printf("pa\n");
	return (s);
}

t_data	*pb(t_data *s)
{
	t_stack	*first;

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
	fix_head_b(s->b, first);
	s->b = first;
	s->a_size--;
	s->b_size++;
	s->moves++;
	// printf("pb\n");
	return (s);
}

void	fix_head_a(t_stack *a, t_stack *first)
{
	if (!a)
	{
		first->next = first;
		first->prev = first;
	}
	else
	{
		first->next = a;
		first->prev = a->prev;
		a->prev->next = first;
		a->prev = first;
	}
}

void	fix_head_b(t_stack *b, t_stack *first)
{
	if (!b)
	{
		first->next = first;
		first->prev = first;
	}
	else
	{
		first->next = b;
		first->prev = b->prev;
		b->prev->next = first;
		b->prev = first;
	}
}
