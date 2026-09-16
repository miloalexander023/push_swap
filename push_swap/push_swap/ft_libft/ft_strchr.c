/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:20:27 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 14:23:31 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	str;

	str = (unsigned char)c;
	while (*s)
	{
		if (*s == str)
			return ((char *)s);
		s++;
	}
	if (str == '\0')
		return ((char *)s);
	return (NULL);
}
// int main(void)
// {
// 	const char *str = "search for f in this string";
// 	char *test;
// 	// char *test2;

// 	test = ft_strchr(str, 'f');
// 	if (test == NULL)
// 		printf("not found\n");
// 	else
// 		printf("%s\n", test);
// 	// test2 = strchr(str, 'f');
// 	// if (test2 == NULL)
// 	// 	printf("not found\n");
// 	// else
// 	// 	printf("%s\n", test2);
// 	return 0;
// }
