/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:51:29 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:21 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 0);
	else if (n < 0)
	{
		ft_putchar_fd('-', 0);
		ft_putnbr(n * -1);
	}
	else if (n >= 10)
		ft_putnbr(n / 10);
	if (n >= 0)
		ft_putchar_fd(n % 10 + '0', 0);
}
