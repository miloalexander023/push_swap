/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:08:01 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/02 17:47:18 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_data *s, char sign)
{
	if (!sign)
		return ;
	if (sign == 'a')
		pos_a(s);
	if (sign == 'b')
		pos_b(s);
}

void	pos_a(t_data *s)
{
	t_stack	*temp;
	int		*sorted;
	int		i;

	sorted = malloc(sizeof(int) * s->a_size);
	temp = s->a;
	i = 0;
	while (i < s->a_size)
	{
		sorted[i] = temp->value;
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	free(sorted);
}

void	pos_b(t_data *s)
{
	t_stack	*temp;
	int		*sorted;
	int		i;

	sorted = malloc(sizeof(int) * s->b_size);
	temp = s->b;
	i = 0;
	while (i < s->b_size)
	{
		sorted[i] = temp->value;
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	free(sorted);
}

int	find_target_pos(t_data *s)
{
	t_stack	*temp;
	t_stack	*best;
	int		i;

	temp = s->a;
	best = NULL;
	i = 0;
	while (i < s->a_size)
	{
		if (temp->value > s->b->value)
		{
			if (!best || temp->value < best->value)
				best = temp;
		}
		temp = temp->next;
		i++;
	}
	if (!best)
		return (0);
	return (best->pos);
}
