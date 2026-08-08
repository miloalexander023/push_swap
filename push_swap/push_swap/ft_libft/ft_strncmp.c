/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:06:34 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 20:32:33 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
}

// int main(void)
// {
// 	// char *dest = "abcdefgh";
// 	// char *dest2 = "abcdefgh";
// 	// char *src = "abcdwxyz";
// 	// char *src2 = "abcdwxyz";
// 	int test1;
// 	int test2;

// 	test1 = ft_strncmp("abcdefgh", "", 0);
// 	printf("%d\n", test1);
// 	test2 = strncmp("abcdefgh", "", 0);
// 	printf("%d\n", test2);
// 	return(0);
// }
