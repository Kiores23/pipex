/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:43:59 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:30 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	**ft_freesplit(char **tab, int index)
{
	while (index >= 0)
	{
		if (tab[index])
			free(tab[index]);
		index--;
	}
	if (tab)
		free(tab);
	return (NULL);
}

size_t	ft_splitcount(const char *s, char c)
{
	char	*ns;
	size_t	count;

	ns = (char *)s;
	count = 0;
	if (!*s)
		return (0);
	while (ns)
	{
		count++;
		while (*ns == c)
			ns++;
		ns = ft_strchr(ns, c);
		if (!c)
			ns = 0;
	}
	if (s[ft_strlen(s) - 1] == c)
		count--;
	return (count);
}

char	**ft_splittab(const char *s, char c, char **split, size_t count)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = -1;
	b = 0;
	while (++i < count)
	{
		while (s[b] == c)
			b++;
		a = b;
		if (ft_strchr(&s[(size_t)a], c))
			b = (size_t)(ft_strchr(&s[(size_t)a], c) - (size_t)s);
		else
			b += ft_strlen((char *)&s[(size_t)a]);
		split[i] = ft_substr(s, (size_t)a, ((size_t)b - (size_t)a));
		if (!split[i])
			return (ft_freesplit(split, i));
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_splitcount(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	return (ft_splittab(s, c, split, count));
}
