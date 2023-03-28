/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:56:16 by amery             #+#    #+#             */
/*   Updated: 2023/03/25 16:43:13 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int n);
void	ft_bzero(int *s, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
long	ft_atoi(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_nbrlen(int nbr);
int		ft_issorta(int *tab, int size, int place);
int		ft_isnumber(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_issortrn(int *tab, int size, int n);
int     ft_rerror(const char *derror);
int		ft_isdigit(char c);

#endif