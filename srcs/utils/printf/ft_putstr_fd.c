/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:01:50 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 17:36:56 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
	{
		pf_putstr_fd("(null)", fd);
		return (6);
	}
	while (s[++i])
		pf_putchar_fd(s[i], fd);
	return (i);
}
