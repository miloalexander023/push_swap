/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:55:19 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 21:57:32 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	concat_length(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

static char	*concat_dest(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < size -1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;

	i = 0;
	j = 0;
	dest_size = ft_strlen(dst);
	if (dest_size < size)
	{
		i = concat_length(dst, src);
		dst = concat_dest(dst, src, size);
	}
	else
	{
		while (i < size)
			i++;
		while (src[j] != '\0')
		{
			i++;
			j++;
		}
		if (size == 0)
			i = ft_strlen((char *)src);
	}
	return (i);
}

// int main(void)
// {
// 	char dest[] = "a";
// 	char dest2[] = "a";
// 	char src[] = "hahahahahaha";
// 	size_t test;
// 	size_t test1;

// 	test = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
// 	printf("%zu\n%s\n", test, dest);
// 	test1 = strlcat(dest2, "lorem ipsum dolor sit amet", 1);
// 	printf("%zu\n%s\n", test1, dest2);
// 	return 0;
// }
