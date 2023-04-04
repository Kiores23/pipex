/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:26:01 by amery             #+#    #+#             */
/*   Updated: 2023/04/04 12:45:45 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_parent(t_pipex *p, int n)
{
	if (p->fd[n + 1][0] > 0)
		close(p->fd[n + 1][0]);
	if (p->fd[n + 2][1] > 0)
		close(p->fd[n + 2][1]);
}

void	process_child(t_pipex *p, char **envp, int n)
{
	int	r;

	r = dup2(p->fd[n + 1][0], 0);
	if (r != -1)
		r = dup2(p->fd[n + 2][1], 1);
	if (p->fd[n + 1][1] > 0)
		close(p->fd[n + 1][1]);
	if (p->fd[n + 2][0] > 0)
		close(p->fd[n + 2][0]);
	if (r == -1)
		exit_process("Error dup2", 4);
	if (!p->c.path_cmd[n] || !p->c.cmds[n])
		exit_process("Error command not found", 127);
	execve(p->c.path_cmd[n], p->c.cmds[n], envp);
	exit_process("Error execve", 126);
}

int	choice_fd(t_pipex *p, int n)
{
	if (n == 0 && pipe(p->fd[0]) == -1)
	{
		perror("Error pipe");
		return (1);
	}
	if (n == 0)
		p->fd[1][0] = p->f.src_fd;
	if (n == p->npipe - 1)
		p->fd[n + 2][1] = p->f.dst_fd;
	else
		pipe(p->fd[n + 2]);
	return (0);
}

int	pipe_master(t_pipex *p, char **envp)
{
	int	i;

	i = -1;
	while (++i < p->npipe)
	{
		if (choice_fd(p, i))
			return (1);
		p->id[i] = fork();
		if (p->id[i] == -1)
		{
			perror("Error fork");
			return (1);
		}
		else if (p->id[i] == 0)
			process_child(p, envp, i);
		process_parent(p, i);
	}
	return (0);
}
