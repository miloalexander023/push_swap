/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:32:47 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/17 20:17:21 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_two(t_stack *first, t_stack *second)
{
	t_stack	*prev;
	t_stack	*next;

	prev = first->prev;
	next = second->next;
	prev->next = second;
	second->prev = prev;
	second->next = first;
	first->prev = second;
	first->next = next;
	next->prev = first;
}

t_data	*sa(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s->a || s->a->next == s->a)
		return (s);
	first = s->a;
	second = first->next;
	if (second->next != first)
		swap_two(first, second);
	s->a = second;
	s->moves++;
	write(1, "sa\n", 3);
	return (s);
}

t_data	*sb(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s->b || s->b->next == s->b)
		return (NULL);
	first = s->b;
	second = first->next;
	if (second->next != first)
		swap_two(first, second);
	s->b = second;
	s->moves++;
	write(1, "sb\n", 3);
	return (s);
}

t_data	*ss(t_data *s)
{
	int	old_moves;

	old_moves = s->moves;
	sa(s);
	sb(s);
	s->moves = old_moves + 1;
	write(1, "ss\n", 3);
	return (s);
}
