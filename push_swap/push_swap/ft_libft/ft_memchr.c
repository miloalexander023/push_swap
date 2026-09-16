/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:15:23 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/06 17:34:24 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;
	char		first_occur;

	i = 0;
	str = (const char *)s;
	first_occur = (char)c;
	while (i < n)
	{
		if (*str == first_occur)
			return ((char *)str);
		str++;
		i++;
	}
	if (first_occur == '\0' && *str == '\0' && n != 0)
		return ((char *)str);
	return (NULL);
}
// int main(void)
// {
// 	const char *str = "search for f in this string";
// 	char *test;
// 	char *test2;

// 	test = ft_memchr(s, 0, 0);
// 	if (test == NULL)
// 		printf("not found\n");
// 	else
// 		printf("%s\n", test);
// 	// test2 = memchr(str, 'f', 10);
// 	// if (test2 == NULL)
// 	// 	printf("not found\n");
// 	// else
// 	// 	printf("%s\n", test2);
// 	return 0;
// }
