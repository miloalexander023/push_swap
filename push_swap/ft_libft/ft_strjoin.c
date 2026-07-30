/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:02:34 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 21:54:09 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	ft_strlen2(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		slen1;
	int		slen2;

	slen1 = ft_strlen2(s1);
	slen2 = ft_strlen2(s2);
	join = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (join == 0)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join - slen1 - slen2);
}

// int main(void)
// {
// 	char *arr1;

// 	arr1 = ft_strjoin("concatenate", " this");
// 	if (arr1 == NULL)
// 	{
// 		printf("no memory allocated!\n");
// 		return 1;
// 	}
// 	printf("%s\n", arr1);

// 	return 0;
// }
