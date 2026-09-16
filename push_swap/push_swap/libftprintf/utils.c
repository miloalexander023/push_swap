/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:10:01 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/24 15:13:30 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../ft_libft/libft.h"
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 

int	put_ptr(void *ptr)
{
	unsigned long	addres;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addres = (unsigned long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += to_hex_ptr("0123456789abcdef", addres, 0);
	return (count);
}

int	ft_put_u_nbr_fd(unsigned int nb, int fd)
{
	char		c;
	int			count;

	count = 0;
	if (nb >= 10)
		count += ft_put_u_nbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	check_nbr_length(unsigned long tmp)
{
	int	i;

	i = 0;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		tmp /= 16;
		i++;
	}
	return (i);
}

int	to_hex(char *decimal, unsigned int num, int width)
{
	int				i;
	char			*hex;
	unsigned int	tmp;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	tmp = num;
	i = check_nbr_length((unsigned long)tmp);
	if (width < i)
		width = i;
	hex = malloc(width);
	tmp = num;
	while (--width >= 0)
	{
		hex[width] = decimal[tmp % 16];
		tmp /= 16;
	}
	write(1, hex, i);
	free(hex);
	return (i);
}

int	to_hex_ptr(char *decimal, unsigned long num, int width)
{
	int				i;
	char			*hex;
	unsigned long	tmp;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	tmp = num;
	i = check_nbr_length(tmp);
	if (width < i)
		width = i;
	hex = malloc(width);
	tmp = num;
	while (--width >= 0)
	{
		hex[width] = decimal[tmp % 16];
		tmp /= 16;
	}
	write(1, hex, i);
	free(hex);
	return (i);
}
