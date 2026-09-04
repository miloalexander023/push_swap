/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:12:51 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/04 18:19:59 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libftprintf.a/ft_printf.h"

void	sort_stack_of_3(t_data *s)
{
	int	a;
	int	b;
	int	c;

	a = s->a->value;
	b = s->a->next->value;
	c = s->a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(s);
		ra(s);
	}
	else if (b < a && a < c)
		sa(s);
	else if (c < a && a < b)
		rra(s);
	else if (b < c && c < a)
		ra(s);
	else if (c < b && b < a)
	{
		sa(s);
		rra(s);
	}
}

void	push_back_to_a(t_data *s)
{
	int	target_pos;

	while (s->b_size > 0)
	{
		update_pos(s, 'a');
		update_pos(s, 'b');
		find_targetnumber_b(s);
		target_pos = find_target_pos(s);
		if (target_pos != 0)
			rotate_a_to_pos(s, target_pos);
		pa(s);
	}
}
// void	push_back_to_a(t_data *s)
// {
// 	int	target_pos;

// 	while (s->b_size > 0)
// 	{
// 		update_pos(s, 'a');
// 		update_pos(s, 'b');
// 		target_pos = find_target_pos(s);
// 		if (target_pos != 0)
// 			rotate_a_to_pos(s, target_pos);
// 		pa(s);
// 	}
// }

void	rotate_a_to_pos(t_data *s, int target_pos)
{
	if (target_pos <= s->a_size / 2)
	{
		while (target_pos > 0)
		{
			ra(s);
			target_pos--;
		}
	}
	else
	{
		target_pos = s->a_size - target_pos;
		while (target_pos > 0)
		{
			rra(s);
			target_pos--;
		}
	}
}

void	final_rotations(t_data *s)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		i;
	int		pos;

	update_pos(s, 'a');
	smallest = s->a;
	temp = s->a->next;
	i = 0;
	while (i < s->a_size)
	{
		if (temp->value < smallest->value)
			smallest = temp;
		temp = temp->next;
		i++;
	}
	pos = smallest->pos;
	rotate_a_to_pos(s, pos);
}

t_data	*turk_sort(t_data *s)
{
	t_stack	*push_nbr;
	int		i;

	i = 0;
	if (!s || !s->a)
		return (NULL);
	if (is_sorted(s))
		return (s);
	if (s->a_size > 3)
	{
		pb(s);
		pb(s);
		if (s->b->value < s->b->next->value)
		{
			printf("b->value: %d\n", s->b->value);
			printf("b->next->value: %d\n", s->b->next->value);

			sb(s);
		}
	}
	while(s->a_size > 3)
	{
		update_pos(s, 'a');
		update_pos(s, 'b');
		find_targetnumber_a(s);
		rotation_cost(s);
		push_nbr = cheapest(s);
		rotate_push(s, push_nbr);
	}
	if (s->a_size == 3)
		sort_stack_of_3(s);
	update_pos(s, 'a');
	update_pos(s, 'b');
	push_back_to_a(s);
	final_rotations(s);
	printf("moves: %d\n", s->moves);
	return (s);
}