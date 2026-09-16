/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:19:41 by milalexa          #+#    #+#             */
/*   Updated: 2024/11/05 21:53:36 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	free_mem(char **arr, int length)
{
	int	j;

	j = 0;
	while (j < length)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static char	*allocate_word(const char *s, int wordlen)
{
	char	*word;
	int		i;

	word = (char *)malloc((wordlen + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		word[i] = s[i];
		i++;
	}
	word[wordlen] = '\0';
	return (word);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**whileloop(char const *s, char c, char **arr, int count)
{
	int	i;
	int	length;
	int	wordlen;

	i = 0;
	length = 0;
	while (length < count)
	{
		while (s[i] == c)
			i++;
		wordlen = 0;
		while (s[i + wordlen] != c && s[i + wordlen] != '\0')
			wordlen++;
		arr[length] = allocate_word(&s[i], wordlen);
		if (!arr[length])
		{
			free_mem(arr, length);
			return (NULL);
		}
		i = i + wordlen;
		length++;
	}
	arr[length] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	count = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr = whileloop(s, c, arr, count);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

// int	main(void)
// {
// 	char	str[] = "splitathisastring";
// 	char	occurence = 'a';
// 	char	**arr;
// 	int		i;

// 	i = 0;
// 	arr = ft_split(str, occurence); // Get the array of strings
// 	if (arr != NULL)
// 	{
// 		while (arr[i] != NULL)
// 		{
// 			printf("%s\n", arr[i]);
// 			i++;
// 		}
// 		free_mem(arr, i);
// 	}
// 	return (0);
// }
