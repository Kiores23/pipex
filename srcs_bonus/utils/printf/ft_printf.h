/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:54:01 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 17:35:55 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../pipex_utils.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	pf_putchar_fd(char c, int fd);
int	pf_putstr_fd(char *s, int fd);
int	ft_putnbr_base_fd(long nb, char *base, int fd);
int	ft_putptr_fd(size_t nb, char *base, int fd, int p);

#endif
