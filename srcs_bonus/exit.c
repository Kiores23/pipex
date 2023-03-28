/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:52:59 by amery             #+#    #+#             */
/*   Updated: 2023/03/27 20:35:31 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_pipex(void *v, int ret, const char *msg)
{
	t_pipex *p;
	int		i;
	int		j;

	p = v;
	if (p)
	{
		i = -1;
		while (p->c.cmds && p->c.cmds[++i])
		{
			j = -1;
			while (p->c.cmds[i][++j])
			{
				//printf("%s\n", p->c.cmds[i][j]);
				free(p->c.cmds[i][j]);
			}
			free(p->c.cmds[i]);
		}
		if (p->c.cmds)
			free(p->c.cmds);
		i = -1;
		while (p->c.path_cmd && p->c.path_cmd[++i])
			free(p->c.path_cmd[i]);
		if (p->c.path_cmd)
			free(p->c.path_cmd);
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
		ft_printf("Error : ", msg);
	if (msg)
		ft_printf("%s\n", msg);
	ft_printf("\n\n");
	system("leaks pipex");
	return (ret);
}