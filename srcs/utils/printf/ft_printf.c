/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:40:13 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 17:37:20 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pargs(const char *str, va_list args)
{
	if (*str == 'c')
		return (pf_putchar_fd((char)va_arg(args, int), 1) - 1);
	else if (*str == 's')
		return (pf_putstr_fd((char *)va_arg(args, char *), 1) - 1);
	else if (*str == 'p')
		return (ft_putptr_fd((size_t)va_arg(args, void *),
				"0123456789abcdef", 1, 2) - 1);
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_base_fd((int)va_arg(args, int), "0123456789", 1) - 1);
	else if (*str == 'u')
		return (ft_putnbr_base_fd((unsigned int)va_arg(args, unsigned int),
				"0123456789", 1) - 1);
	else if (*str == 'x')
		return (ft_putptr_fd((unsigned int)va_arg(args, unsigned int),
				"0123456789abcdef", 1, 0) - 1);
	else if (*str == 'X')
		return (ft_putptr_fd((unsigned int)va_arg(args, unsigned int),
				"0123456789ABCDEF", 1, 0) - 1);
	else
		return (pf_putchar_fd(*str, 1) - 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	if (!str)
		return (0);
	i = -1;
	size = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			size += ft_pargs(&str[++i], args);
		else
			pf_putchar_fd(str[i], 1);
		size++;
	}
	va_end(args);
	return (size);
}
