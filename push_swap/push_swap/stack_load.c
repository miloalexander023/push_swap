/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:45:27 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/16 23:57:55 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libftprintf.a/ft_printf.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->cost = 0;
	node->target = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_stacktail(t_stack **head, t_stack *new)
{
	t_stack	*tail;

	if (!*head)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	tail = (*head)->prev;
	tail->next = new;
	new->prev = tail;
	new->next = *head;
	(*head)->prev = new;
}

void	fill_stack_a(t_data *data, char **argv, int argc)
{
	int		i;
	long	value;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		value = ft_atol_checked(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			return ;
		new = new_node((int)value);
		if (!new)
			return ;
		// if (!check_dup(data->a, (int)value))
		// 	printf("oh no!\n");
		add_to_stacktail(&data->a, new);
		data->a_size++;
		i++;
	}
}

void	free_stack(t_stack *s, int size)
{
	t_stack	*current;
	t_stack	*next;
	int		i;

	if (!s)
		return ;
	current = s;
	i = 0;
	while (i < size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
}
