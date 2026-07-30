/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:55:56 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 21:55:24 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	ft_strlen3(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// char	f(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (c >= 'a' && c <= 'z')
// 			c -= 32;
// 		if (c >= 'A' && c <= 'A')
// 			c += 32;
// 	}
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	new_s = (char *)malloc(sizeof(char) * (ft_strlen3(s) + 1));
	if (!new_s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

// int main(void)
// {
// 	char str[] = "LoReM iPsUm";
// 	char *arr;

// 	arr = ft_strmapi(str, &f);
// 	printf("%s\n", arr);

// 	return (0);
// }
