/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:56:40 by milalexa          #+#    #+#             */
/*   Updated: 2024/10/29 21:00:16 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (size == 0)
	{
		i = ft_strlen((char *)src);
		return (i);
	}
	else
	{
		while (src[i] != '\0')
		{
			i++;
		}
		while (src[j] != '\0' && j < size -1)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
// int main(void)
// {
// 	char dest[] = "copy to this string";
// 	char dest2[] = "copy to this string";
// 	char src[] = "haha";
// 	char test;
// 	char test1;

// 	test = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 10);
// 	printf("%d\n%s\n", test, dest);
// 	test1 = strlcpy(dest2, "lorem ipsum dolor sit amet", 10);
// 	printf("%d\n%s\n", test1, dest2);
// 	return (0);
// }
