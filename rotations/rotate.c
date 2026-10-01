/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:18:32 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/17 20:15:24 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*ra(t_data *s)
{
	if (!s->a || s->a->next == s->a)
		return (s);
	s->a = s->a->next;
	s->moves++;
	write(1, "ra\n", 3);
	return (s);
}

t_data	*rb(t_data *s)
{
	if (!s->b || s->b->next == s->b)
		return (s);
	s->b = s->b->next;
	s->moves++;
	write(1, "rb\n", 3);
	return (s);
}

t_data	*rr(t_data *s)
{
	if (s->a && s->a->next != s->a)
		s->a = s->a->next;
	if (s->b && s->b->next != s->b)
		s->b = s->b->next;
	s->moves++;
	write(1, "rr\n", 3);
	return (s);
}
