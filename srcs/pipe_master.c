/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:26:01 by amery             #+#    #+#             */
/*   Updated: 2023/04/03 15:33:41 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_parent(t_pipex *p)
{
	close(p->fd[0]);
	close(p->fd[1]);
	close(p->f.src_fd);
	close(p->f.dst_fd);
}

void	process_child(t_pipex *p, char **envp, int n)
{
	int	r;

	if (n == 0)
	{
		r = dup2(p->f.src_fd, 0);
		if (r != -1)
			r = dup2(p->fd[1], 1);
		close(p->fd[0]);
	}
	else
	{
		r = dup2(p->fd[0], 0);
		if (r != -1)
			r = dup2(p->f.dst_fd, 1);
		close(p->fd[1]);
	}
	close(p->f.src_fd);
	close(p->f.dst_fd);
	if (r == -1)
		exit_process("Error dup2", 4);
	if (!p->c.path_cmd[n] || !p->c.cmds[n])
		exit_process("Error command not found", 127);
	execve(p->c.path_cmd[n], p->c.cmds[n], envp);
	exit_process("Error execve", 126);
}

int	pipe_master(t_pipex *p, char **envp)
{
	int	i;

	if (pipe(p->fd) == -1)
	{
		perror("Error pipe");
		return (1);
	}
	i = -1;
	while (++i < 2)
	{
		p->id[i] = fork();
		if (p->id[i] == -1)
		{
			perror("Error fork");
			return (1);
		}
		else if (p->id[i] == 0)
			process_child(p, envp, i);
	}
	process_parent(p);
	return (0);
}
