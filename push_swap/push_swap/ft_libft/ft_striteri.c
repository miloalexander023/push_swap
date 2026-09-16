/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:20:59 by milalexa          #+#    #+#             */
/*   Updated: 2024/10/29 19:21:25 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	f(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c -= 32;
	}
	else
		if (*c >= 'A' && *c <= 'A')
			*c += 32;
}

void	*ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "hello world";
// 	char *arr;

// 	arr = ft_striteri(str, f);
// 	printf("%s\n", str);
// 	return (0);
// }
