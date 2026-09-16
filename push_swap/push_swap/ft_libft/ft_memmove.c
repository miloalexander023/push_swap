/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:16:10 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 14:22:48 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (dest1 == src1 || n == 0)
		return (dest1);
	if (dest1 > src1)
	{
		while (n > 0)
		{
			dest1[n -1] = src1[n -1];
			n--;
		}
		return (dest1);
	}
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

// int main(void)
// {
// 	char dest[40] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	char *src = "\0";
// 	char *test;
// 	char *test1;
//
// 	test = ft_memmove(dest, dest + 4, 8);
// 	printf("%s\n", test);
// 	// test1 = memmove(dest, dest + 4, 8);
// 	// printf("%s\n", test1);
// 	return 0;
// }
