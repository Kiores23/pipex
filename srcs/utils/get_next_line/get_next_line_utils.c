/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:30 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 19:36:24 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_create_str(char *s1, char *s2)
{
	int		l1;
	int		l2;

	l1 = 0;
	l2 = 0;
	while (s1 && s1[l1])
		l1++;
	while (s2 && s2[l2])
		l2++;
	if (l1 + l2)
		return ((char *)malloc(sizeof(char) * (l1 + l2 + 1)));
	return (NULL);
}

void	ft_strlcpy2(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (--size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = ft_create_str(s1, s2);
	if (!str)
		return (ft_free_stackandbuff(&s1, NULL));
	i = 0;
	j = -1;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
