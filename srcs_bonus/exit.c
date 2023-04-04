/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:52:59 by amery             #+#    #+#             */
/*   Updated: 2023/04/04 13:11:12 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	freetab(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
	return (0);
}

void	exit_process(const char *msg, int r)
{
	perror(msg);
	exit(r);
}

int	exit_pipex(void *v, int ret, const char *msg)
{
	t_pipex	*p;
	int		i;

	p = v;
	if (p)
	{
		i = -1;
		while (p->c.cmds && p->c.cmds[++i])
			freetab(p->c.cmds[i]);
		if (p->c.cmds)
			free(p->c.cmds);
		freetab(p->c.path_cmd);
		if (p->f.src)
			free(p->f.src);
		if (p->f.dst)
			free(p->f.dst);
	}
	if (v && p->f.src_fd >= 0)
		close(p->f.src_fd);
	if (v && p->f.dst_fd >= 0)
		close(p->f.dst_fd);
	if (msg)
		perror(msg);
	return (ret);
}
