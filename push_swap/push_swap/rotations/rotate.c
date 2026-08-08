/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:18:32 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/06 15:47:37 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*ra(t_data *s)
{
	t_stack *first;
	
	if (!s->a || s->a->next == s->a)
		return NULL;
	first = s->a;
	s->a->prev->next = first;
	first->next = s->a->next;
	first->prev = s->a->prev;
	s->a = s->a->next;
	s->a->prev = first;
	printf("ra\n");
	return (s);
}

t_data	*rb(t_data *s)
{
	t_stack *first;
	
	if (!s->b || s->b->next == s->b)
		return NULL;
	first = s->b;
	s->b->prev->next = first;
	first->next = s->b->next;
	first->prev = s->b->prev;
	s->b = s->b->next;
	s->b->prev = first;
	printf("rb\n");
	return (s);
}

t_data *rr(t_data *s)
{
	ra(s);
	rb(s);
	printf("rr\n");
	return (s);
}