/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:42:26 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/08 17:32:59 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_libft/libft.h"

void	printlist(t_stack *head)
{
	t_stack *temp;
	
	if (!head)
		return ;
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
		if (temp == head)
			break ;
	}
}

long    ft_atol_checked(const char *str)
{
    long    result;
    int     sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    if (!*str)
        return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            return (0);
        str++;
    }
    return (result * sign);
}

int	main(int argc, char **argv)
{
	t_data data;
	t_stack *temp1;
	t_stack *temp2;
	int i;

	i = 0;
	if (argc == 1 || argc == 2)
		return (1);
	data.a = NULL;
	data.b = NULL;
	data.a_size = 0;
	data.b_size = 0;
	fill_stack_a(&data, argv, argc);
	pb(&data);
	pb(&data);
	pb(&data);

	// printlist(data.a);
	// sa(&data);
	// printlist(data.a);
	// while (i != 3)
	// {
	// 	printf("push %d\n", i);
	// 	pb(&data);
	// 	printlist(data.a);
	// 	printlist(data.b);
	// 	i++;
	// }
	// printf("stack_size: %d\n", data.a_size);
	determin_index(&data, 'a');
	update_pos(&data, 'a');
	//turk_sort(&data)
	temp2 = data.b;
	temp1 = data.a;
	i = 0;
	determin_index(&data, 'b');
	update_pos(&data, 'b');
	printlist(data.b);
	find_targetnumber(&data);
	printf("stack_a\n");
	while (i < data.a_size)
	{
		printf("value: %d		index: %d		pos: %d		target: %d\n", temp1->value, temp1->index, temp1->pos, temp1->target);
		temp1 = temp1->next;
		i++;
	}
	i = 0;
	printf("\nstack_b\n");
	while (i < data.b_size)
	{
		printf("value: %d		index: %d		pos: %d\n", temp2->value, temp2->index, temp2->pos);
		temp2 = temp2->next;
		i++;
	}
	//if (is_sorted(&data))
	//	return (0);
	//free_stack(&data.a);
	//free_stack(&data.b);
	return (0);
}



// ra(&data);
// printf("stack_a\n");
// printlist(data.a);
// rra(&data);
// printf("hello\n");
// printf("stack_a\n");
// printlist(data.a);
// rb(&data);;
// printf("stack_b\n");
// printlist(data.b);
// rrb(&data);
// printf("stack_b\n");
// printlist(data.b);