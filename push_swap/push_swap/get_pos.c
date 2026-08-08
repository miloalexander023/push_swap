/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:08:01 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/08 16:17:05 by miloalex         ###   ########.fr       */
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
	int *sorted;
	t_stack	*temp;
	int i;

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
	int *sorted;
	t_stack	*temp;
	int i;

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