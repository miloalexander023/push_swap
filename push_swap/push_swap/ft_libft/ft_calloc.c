/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:00:37 by milalexa          #+#    #+#             */
/*   Updated: 2025/11/17 16:16:44 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	size_t	total;
	void	*ptr;

	if (number != 0 && (__SIZE_MAX__ / number) < size)
		return (NULL);
	total = number * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
// int main(void)
// {
// 	int *arr1;
// 	int *arr2;
// 	size_t i;
// 	size_t number;
// 	number = 10;
// 	i = 0;
// 	arr1 = (int *)ft_calloc(number, sizeof(int));
// 	if (arr1 == NULL)
// 	{
// 		printf("no memory allocated!\n");
// 		return 1;
// 	}
// 	while(i < number)
// 	{
// 		printf("%d", arr1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(arr1);
// 	// arr2 = (int *)calloc(5, sizeof(int));
// 	// if (arr2 == NULL)
// 	// {
// 	// 	printf("no memory allocated!\n");
// 	// 	return 1;
// 	// }
// 	// while(i < 5)
// 	// {
// 	// 	printf("%d", arr2[i]);
// 	// 	i++;
// 	// }
// 	// free(arr2);
// 	return 0;
// }
