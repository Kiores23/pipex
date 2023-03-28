/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:26:01 by amery             #+#    #+#             */
/*   Updated: 2023/03/27 20:39:50 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process(t_pipex *p, char **envp, int n)
{
	if (n == 0)
	{
		dup2(p->f.src_fd, 0);
		dup2(p->fd[1], 1);
		close(p->fd[0]);
	}
	if (n == 1)
	{
		dup2(p->fd[0], 0);
		dup2(p->f.dst_fd, 1);
		close(p->fd[1]);
	}
	execve(p->c.path_cmd[n], p->c.cmds[n], envp);
	return (1);
}

int	pipe_master(t_pipex p, char **envp)
{
	pipe(p.fd);
	p.id[0] = fork();
	if (p.id[0] == -1)
		return (1);
	else if (p.id[0] == 0)
		return (process(&p, envp, 0));
	p.id[1] = fork();
	if (p.id[1] == -1)
		return (1);
	else if (p.id[1] == 0)
		return (process(&p, envp, 1));
	waitpid(-1, NULL, 0);
	return (0);
}