/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:17:14 by milalexa          #+#    #+#             */
/*   Updated: 2024/10/29 19:17:30 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
// int main(void)
// {
// 	char str[] = "hello world!";
// 	char c = 'A';
// 	char *test;
// 	char *test1;

// 	// test = (char *)ft_memset(str, c, 7);
// 	// printf("%s\n", test);
// 	test1 = memset(str, c, 7);
// 	printf("%s\n", test1);
// 	return 0;
// }
