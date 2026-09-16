/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:13:05 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/24 15:54:31 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../ft_libft/libft.h"
// #include <stddef.h>
// #include <unistd.h>
// #include <limits.h>

int	applysign(char sign, va_list *args)
{
	int	count;

	count = 0;
	if (sign == 'c')
		count += ft_putchar_fd((char)va_arg(*args, int), 1);
	else if (sign == 's')
		count += ft_putstr_fd(va_arg(*args, char *), 1);
	else if (sign == 'p')
		count += put_ptr(va_arg(*args, void *));
	else if (sign == 'd' || sign == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (sign == 'u')
		count += ft_put_u_nbr_fd(va_arg(*args, unsigned int), 1);
	else if (sign == 'X')
		count += to_hex("0123456789ABCDEF", va_arg(*args, unsigned int), 0);
	else if (sign == 'x')
		count += to_hex("0123456789abcdef", va_arg(*args, unsigned int), 0);
	else if (sign == '%')
	{
		count++;
		write(1, "%%", 1);
	}
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, text);
	i = 0;
	count = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '%' && text[i + 1] != '\0')
		{
			i++;
			count += applysign (text[i], &args);
		}
		else
		{
			count++;
			write (1, &text[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	count;

// 	count = 0;
// 	printf("\nmy printf\n");
// 	count = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf("\nmy total:%d\n", count);
// 	printf("\n\n");
// 	count = 0;
// 	printf("\nreal printf\n");
// 	count = printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf("\nprintf total:%d\n", count);
// 	return (0);
// }
