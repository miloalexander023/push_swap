/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:32:47 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/04 17:24:19 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*sa(t_data *s)
{
	t_stack *first;
	t_stack *second;
	t_stack	*prev;
	t_stack	*next;
	if (!s->a || s->a->next == s->a)
		return (s);
	first = s->a;
	second = first->next;
	if (second->next == first)
	{
		s->a = second;
		s->moves++;
		return (s);
	}
	prev = first->prev;
	next = second->next;
	prev->next = second;
	second->prev = prev;
	second->next = first;
	first->prev = second;
	first->next = next;
	next->prev = first;
	s->a = second;
	s->moves++;
	return (s);
}

t_data	*sb(t_data *s)
{
	t_stack *first;
	t_stack *second;
	t_stack	*prev;
	t_stack	*next;
	if (!s->b || s->b->next == s->b)
		return NULL;
	first = s->b;
	second = first->next;
	prev = first->prev;
	next = second->next;
	prev->next = second;
	second->prev = prev;
	second->next = first;
	first->prev = second;
	first->next = next;
	next->prev = first;
	s->b = second;
	s->moves++;
	return (s);
}

t_data *ss(t_data *s)
{
	int old_moves;
	old_moves = s->moves;
	sa(s);
	sb(s);
	s->moves = old_moves + 1;
	// printf("ss\n");
	return (s);
}