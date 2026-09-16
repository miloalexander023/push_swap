/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:01:33 by milalexa          #+#    #+#             */
/*   Updated: 2025/11/17 16:16:14 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*check_specialcase(void)
{
	char	*str;

	str = (char *)malloc(12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", (ft_strlen("-2147483648") + 1));
	return (str);
}

int	find_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*create_string(int n, int x, int negative)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (x + negative + 1));
	if (!str)
		return (NULL);
	str[x + negative] = '\0';
	while (n != 0)
	{
		str[x + negative - 1] = (n % 10) + '0';
		n = n / 10;
		x--;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		x;
	int		negative;
	char	*str;

	x = 0;
	negative = 0;
	if (n == -2147483648)
		return (check_specialcase());
	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	x = find_len(n);
	return (create_string(n, x, negative));
}

// int main(void)
// {
// 	char *arr;

// 	arr = ft_itoa(214116148);
// 	printf("%s\n", arr);
// 	return(0);
// }
