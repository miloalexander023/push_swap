/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:07:31 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/23 23:09:13 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../ft_libft/libft.h"

int		applysign(char sign, va_list *args);
int		ft_printf(const char *text, ...);
int		ft_put_u_nbr_fd(unsigned int nb, int fd);
int		to_hex(char *decimal, unsigned int num, int width);
int		to_hex_ptr(char *decimal, unsigned long num, int width);
int		put_ptr(void *ptr);
int		check_nbr_length(unsigned long tmp);

#endif