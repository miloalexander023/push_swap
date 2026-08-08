/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:07:36 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 20:44:43 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_look_in_set(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		len;
	int		trim_i;

	i = 0;
	trim_i = 0;
	len = ft_strlen((char *)s1) - 1;
	while (ft_look_in_set(s1[i], set))
		i++;
	while (len >= i && ft_look_in_set(s1[len], set))
		len--;
	trimmed = (char *)malloc(sizeof(char) * (len - i +2));
	if (trimmed == NULL)
		return (NULL);
	while (i <= len)
	{
		trimmed[trim_i] = s1[i];
		trim_i++;
		i++;
	}
	trimmed[trim_i] = '\0';
	return (trimmed);
}

// int main(void)
// {
// 	char  *s1 = "ahdahdhfhfadhfdfhfaaa";
// 	char  *set = "dfha";
// 	char *arr1;

// 	arr1 = ft_strtrim(s1, set);
// 	if (arr1 == NULL)
// 	{
// 		printf("nothing to trim\n");
// 		return 1;
// 	}
// 	printf("%s\n", arr1);

// 	return 0;
// }
