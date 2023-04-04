/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:59:41 by amery             #+#    #+#             */
/*   Updated: 2023/04/04 13:27:13 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define _POSIX_SOURCE

char	**initcmd(char *str)
{
	char	**cmds;
	char	*tmp;

	cmds = NULL;
	tmp = ft_strdup(str);
	if (tmp)
		cmds = ft_split(tmp, ' ');
	if (tmp)
		free(tmp);
	return (cmds);
}

char	*get_path(char **tmp, char *cmd)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (tmp[++i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		tmp[i] = ft_strjoin(tmp[i], cmd);
		if (!access(tmp[i], F_OK | X_OK))
			break ;
	}
	if (tmp[i])
		path = ft_strdup(tmp[i]);
	return (path);
}

char	*get_bin_path(char **enpv, char *cmd)
{
	char	**tmp;
	char	*path;
	int		i;

	i = -1;
	while (enpv[++i] && ft_strncmp(enpv[i], "PATH=", 5))
		;
	if (!enpv[i])
		return (NULL);
	tmp = ft_split(enpv[i] + 5, ':');
	if (!tmp)
		return (NULL);
	path = get_path(tmp, cmd);
	i = -1;
	while (tmp && tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (path);
}

int	init(int argc, char **argv, t_pipex *p, char **enpv)
{
	int	i;

	p->f.src = ft_strdup(argv[1]);
	p->f.dst = ft_strdup(argv[argc - 1]);
	p->f.src_fd = -1;
	p->f.dst_fd = -1;
	p->c.cmds = malloc(sizeof(char *) * argc - 2);
	p->c.path_cmd = malloc(sizeof(char *) * argc - 2);
	if (!p->c.cmds || !p->c.path_cmd)
		return (0);
	p->c.cmds[argc - 3] = NULL;
	p->c.path_cmd[argc - 3] = NULL;
	i = 1;
	while (++i <= argc - 2)
	{
		p->c.cmds[i - 2] = initcmd(argv[i]);
		p->c.path_cmd[i - 2] = get_bin_path(enpv, *p->c.cmds[i - 2]);
	}
	p->f.src_fd = open(p->f.src, O_RDONLY, 0644);
	p->f.dst_fd = open(p->f.dst, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (!p->f.src || !p->f.dst || p->f.src_fd == -1 || p->f.dst_fd == -1)
		return (1);
	return (0);
}
