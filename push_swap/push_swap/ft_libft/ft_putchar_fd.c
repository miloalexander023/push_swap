/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:17:38 by milalexa          #+#    #+#             */
/*   Updated: 2026/03/03 19:15:38 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

// int main(void)
// {
// 	// int fd = 
// 	ft_putchar_fd('c', fd);
// 	return 0;	
// }
