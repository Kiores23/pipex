/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:52:59 by amery             #+#    #+#             */
/*   Updated: 2023/03/28 14:13:17 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_pipex(void *v, int ret, const char *msg)
{
	t_pipex *p;
	int		i;

	p = v;
	if (p)
	{
		i = -1;
		while (p->c.cmds[0][++i])
			free(p->c.cmds[0][i]);
		i = -1;
		while (p->c.cmds[1][++i])
			free(p->c.cmds[1][i]);
		if (p->f.src)
			free(p->f.src);
		if (p->f.dst)
			free(p->f.dst);
	}
	if (v && p->f.src_fd >= 0)
		close(p->f.src_fd);
	if (v && p->f.dst_fd >= 0)
		close(p->f.dst_fd);
	if (ret > 0)
		perror(msg);
	ft_printf("\n\n");
	system("leaks pipex | grep -a \"Process\" | grep -a \"leak\"");
	return (ret);
}