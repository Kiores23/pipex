/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:26:01 by amery             #+#    #+#             */
/*   Updated: 2023/03/28 19:24:18 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child(t_pipex *p, char **envp, int n)
{
	if (n == 0)
	{
		dup2(p->f.src_fd, 0);
		dup2(p->fd[1], 1);
		close(p->f.src_fd);
		close(p->fd[0]);
		close(p->fd[1]);
	}
	if (n == 1)
	{
		dup2(p->fd[0], 0);
		dup2(p->f.dst_fd, 1);
		close(p->f.dst_fd);
		close(p->fd[0]);
		close(p->fd[1]);
	}
	execve(p->c.path_cmd[n], p->c.cmds[n], envp);
	perror("Error execve");
	close(p->fd[0]);
	close(p->fd[1]);
	exit(1);
}


int	pipe_master(t_pipex *p, char **envp)
{
	int	i;
	
	pipe(p->fd);
	i = -1;
	p->id[0] = 0;
	while (++i < 2)
	{
		if (i == 0 || p->id[i - 1] > 0)
			p->id[i] = fork();
		if (p->id[i] == -1)
			return (1);
		else if (p->id[i] == 0)
			process_child(p, envp, i);
	}
	return (0);
}