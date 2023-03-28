/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:15:13 by amery             #+#    #+#             */
/*   Updated: 2023/03/25 16:42:55 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n-- > 0)
		i++;
	if (n == 0 || ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] == 0)
		return (0);
	if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] > 0)
		return (1);
	else
		return (-1);
}
