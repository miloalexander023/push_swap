/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:15:09 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/06 18:53:50 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	dest1 = (char *)dest;
	src1 = (const char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

// int main(void)
// {
// 	char dest[] = "copy to this string";
// 	char dest1[] = "copy to this string";
// 	int n = 0;

// 	char *test;
// 	char *test1;
// 	printf("1: %s\n", dest);
// 	test = (char *)ft_memcpy(dest, "zy\0xwvu\0\0tsr", n);
// 	write(1, test, n);
// 	write(1, "\n", 1);
// 	printf("1: %s\n", test);
// 	test1 = (char *)memcpy(dest1, "zy\0xwvu\0\0tsr", n);
// 	write(1, test1, n);
// 	write(1, "\n", 1);
// 	printf("2: %s\n", test1);
// 	return (0);
// }
