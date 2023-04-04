/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:44 by amery             #+#    #+#             */
/*   Updated: 2023/04/03 15:07:49 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./utils/pipex_utils.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_files
{
	char	*src;
	char	*dst;
	int		src_fd;
	int		dst_fd;
}			t_files;

typedef struct s_cmds
{
	char	**cmds[2];
	char	*path_cmd[2];
}			t_cmds;

typedef struct s_pipex
{
	t_files	f;
	t_cmds	c;
	int		fd[2];
	int		id[2];
}			t_pipex;

//INIT_C
int		init(int argc, char **argv, t_pipex *p, char **envp);
//EXIT
void	exit_process(const char *msg, int r);
int		exit_pipex(void *p, int ret, const char *msg);
int		freetab(char **str);
//PIPE
int		pipe_master(t_pipex *p, char **envp);

#endif