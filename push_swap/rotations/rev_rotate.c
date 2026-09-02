/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:21:23 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/24 16:28:44 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../printf.h"

t_data	*rra(t_data *s)
{
	if (!s->a || s->a->next == s->a)
		return (s);
	s->a = s->a->prev;
	s->moves++;
	// printf("rra\n");
	return (s);
}

t_data	*rrb(t_data *s)
{
	if (!s->b || s->b->next == s->b)
		return (s);
	s->b = s->b->prev;
	s->moves++;
	// printf("rrb\n");
	return (s);
}

t_data	*rrr(t_data *s)
{
	if (s->a && s->a->next != s->a)
		s->a = s->a->prev;
	if (s->b && s->b->next != s->b)
		s->b = s->b->prev;
	s->moves++;
	// printf("rrr\n");
	return (s);
}