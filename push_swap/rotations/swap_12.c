/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:32:47 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/06 15:39:18 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*sa(t_data *s)
{
	t_stack *temp_1;
	t_stack *temp_2;
	t_stack	*prev;
	t_stack	*next;
	if (!s->a || s->a->next == s->a)
		return NULL;
	temp_1 = s->a;
	temp_2 = s->a->next;
	prev = temp_1->prev;
	next = temp_2->next;
	prev->next = temp_2;
	temp_2->prev = prev;
	temp_2->next = temp_1;
	temp_1->prev = temp_2;
	temp_1->next = next;
	next->prev = temp_1;
	s->a = temp_2;
	printf("sa\n");
	return (s);
}

t_data	*sb(t_data *s)
{
	t_stack *temp_1;
	t_stack *temp_2;
	t_stack	*prev;
	t_stack	*next;
	if (!s->b || s->b->next == s->b)
		return NULL;
	temp_1 = s->b;
	temp_2 = s->b->next;
	prev = temp_1->prev;
	next = temp_2->next;
	prev->next = temp_2;
	temp_2->prev = prev;
	temp_2->next = temp_1;
	temp_1->prev = temp_2;
	temp_1->next = next;
	next->prev = temp_1;
	s->b = temp_2;
	printf("sb\n");
	return (s);
}

t_data *ss(t_data *s)
{
	sa(s);
	sb(s);
	return (s);
}