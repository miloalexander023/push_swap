/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:07:48 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/06 18:07:08 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*whileloop2(char const *s, char *sub, unsigned int x, size_t len)
{
	unsigned int	y;

	y = 0;
	while (len > 0)
	{
		sub[y] = s[x];
		len--;
		y++;
		x++;
	}
	sub[y] = '\0';
	return (sub);
}

char	*allocate_substr(size_t len)
{
	char	*sub;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	x;
	unsigned int	strlen;

	x = 0;
	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start >= strlen)
		return (allocate_substr(0));
	if (len > strlen - start)
		len = strlen - start;
	sub = allocate_substr(len);
	if (sub == NULL)
		return (NULL);
	x = start;
	whileloop2(s, sub, x, len);
	return (sub);
}

// int main(void)
// {
// 	// char str[] = "lorem ipsum dolor sit amet";
// 	char *arr1;

// 	arr1 = ft_substr("hola", 0, 18446744073709551615);
// 	if (arr1 == NULL)
// 	{
// 		printf("no memory allocated!\n");
// 		return 1;
// 	}
// 	printf("%s\n", arr1);
// 	free(arr1);
// 	return 0;
// }
