/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:14:32 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 17:36:17 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_raf_fd(long nb, char *base, int size_b, int fd)
{
	if (nb >= size_b)
		ft_raf_fd(nb / size_b, base, size_b, fd);
	pf_putchar_fd(base[nb % size_b], fd);
}

int	ft_count(long nb, int size_b)
{
	if (nb >= size_b)
		return (1 + ft_count(nb / size_b, size_b));
	return (1);
}

int	ft_putnbr_base_fd(long nb, char *base, int fd)
{
	int		r;

	r = 0;
	if (nb < 0)
	{
		pf_putchar_fd('-', 1);
		nb *= -1;
		r++;
	}
	ft_raf_fd(nb, base, ft_strlen(base), fd);
	r += ft_count(nb, ft_strlen(base));
	return (r);
}
