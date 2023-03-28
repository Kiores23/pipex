/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:50:55 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:15 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	ft_issorta(int *tab, int size, int place)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (place < size - 1)
		{
			if (tab[place] > tab[place + 1])
				return (0);
			place++;
		}
		else
		{
			if (tab[place] > tab[0])
				return (0);
			place = 0;
		}
		i++;
	}
	return (1);
}

int	ft_issortrn(int *tab, int size, int n)
{
	int	i;

	i = 0;
	while (i < size - 1 && i < n - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_isnumber(char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s && ft_isdigit(*s))
		s++;
	if (*s && !ft_isdigit(*s))
		return (0);
	return (1);
}
