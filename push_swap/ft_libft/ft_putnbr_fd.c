/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:19:02 by milalexa          #+#    #+#             */
/*   Updated: 2026/03/04 00:11:04 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putnbr_fd(int nb, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count ++;
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
		count += ft_putnbr_fd(nb / 10, fd);
	count++;
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	return (count);
}

// int main(void)
// {
// 	int count;

// 	count = ft_putnbr_fd(-10, 2);
// 	printf("count: %d", count);
// 	return (0);
// }
