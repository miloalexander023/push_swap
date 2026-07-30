/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:45:27 by miloalex          #+#    #+#             */
/*   Updated: 2026/07/30 21:30:14 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"

t_stack	*new_node(int value)
{
	t_stack *node;

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

void	check_dup(t_stack *a, int value)
{
	t_stack *temp;
	if (a)
		printf("a value: %d\n", a->value);
	if (!a)
	{
		printf("wtf\n");
		return ;
	}
	temp = a;
	while (1)
	{
		if (temp->value == value)
		{
			printf("duplicate number");
			return ;
		}
		temp = temp->next;
		if (temp == a)
			break ;
	}
}

void	add_to_stacktail(t_stack **head, t_stack *new)
{
	t_stack *tail;

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
	int i;
	long value;
	t_stack *new;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = new_node((int)value);
		if (!new)
			return ;
		check_dup(data->a, (int)value);
		printf("succesfull!\n");
		add_to_stacktail(&data->a, new);
		data->a_size++;
		i++;
	}
}
