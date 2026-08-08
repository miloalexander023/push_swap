/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:02:28 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 14:27:55 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
// int main(void)
// {
// 	char *arr1;
// 	char *arr2;

// 	// arr1 = ft_strdup("test");
// 	// if (arr1 == NULL)
// 	// {
// 	// 	printf("no memory allocated!\n");
// 	// 	return 1;
// 	// }
// 	// printf("%s\n", arr1);
// 	// free(arr1);
// 	arr2 = strdup("test");
// 	if (arr2 == NULL)
// 	{
// 		printf("no memory allocated!\n");
// 		return 1;
// 	}
// 	printf("%s\n", arr2);
// 	return 0;
// }
