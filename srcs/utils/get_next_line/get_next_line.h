/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:22 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:55 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include "../pipex_utils.h"

char	*get_next_line(int fd);
char	*ft_free_stackandbuff(char **stack, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen2(char *str);
char	*ft_strchr2(char *str, char c);
void	ft_strlcpy2(char *dst, const char *src, int size);

#endif
