/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:55:36 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 17:06:52 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && (i + j) < len
			&& big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	// const char *str = "search for this word";
// 	// const char *str2 = "search for this word";
// 	// const char *little = "th";
// 	char *test1;
// 	char *test2;

// 	test1 = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
// 	if (test1 == NULL)
// 		printf("not found\n");
// 	else
// 		printf("1: %s\n", test1);
// 	test2 = strnstr("lorem ipsum dolor sit amet", "dolor", 15);
// 	if (test2 == NULL)
// 		printf("not found\n");
// 	else
// 		printf("2: %s\n", test2);
// 	return 0;
// }
