/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:42:26 by miloalex          #+#    #+#             */
/*   Updated: 2026/07/30 21:31:25 by miloalex         ###   ########.fr       */
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

	if (argc == 1 || argc == 2)
		return (1);
	data.a = NULL;
	data.b = NULL;
	data.a_size = 0;
	data.b_size = 0;
	fill_stack_a(&data, argv, argc);
	printlist(data.a);
	//get_indexes(&data);
	//if (is_sorted(&data))
	//	return (0);
	//turk_sort(&data)
	//free_stack(&data.a);
	//free_stack(&data.b);
	return (0);
}