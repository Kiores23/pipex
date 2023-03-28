/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:57:14 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:34 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	t = (char *)s;
	while (*t)
	{
		if (*t == (char)c)
			return (t);
		t++;
	}
	if (*t == (char)c)
		return (t);
	return (NULL);
}
