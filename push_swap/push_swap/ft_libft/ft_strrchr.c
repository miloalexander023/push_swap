/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:44:41 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 20:31:07 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				last_occur;
	unsigned char	str;

	i = 0;
	last_occur = -1;
	str = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == str)
			last_occur = i;
		i++;
	}
	if (str == '\0')
		return ((char *)(s + i));
	if (last_occur != -1)
		return ((char *)(s + last_occur));
	return (NULL);
}
// int main(void)
// {
// 	const char	*str = "bonjour";
// 	const char	*str2 = "bonjour";
// 	char 		*test;
// 	char 		*test2;

// 	if (!(test = ft_strrchr(str +2, 'b')))
// 		printf("not found\n");
// 	else
// 	{
// 		printf("%s\n", test);
// 	}
// 	if (!(test2 = ft_strrchr(str2 +2, 'b')))
// 		printf("not found\n");
// 	else
// 	{
// 		printf("%s\n", test2);
// 	}
// 	return 0;
// }
