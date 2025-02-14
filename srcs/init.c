/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:59:41 by amery             #+#    #+#             */
/*   Updated: 2023/04/03 15:02:16 by amery            ###   ########.fr       */
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

char	*get_bin_path(char **enpv, char *cmd)
{
	char	**tmp;
	char	*path;
	int		i;

	i = -1;
	while (enpv[++i] && ft_strncmp(enpv[i], "PATH=", 5))
		;
	tmp = ft_split(enpv[i] + 5, ':');
	if (!tmp)
		return (NULL);
	i = -1;
	while (tmp[++i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		tmp[i] = ft_strjoin(tmp[i], cmd);
		if (!access(tmp[i], F_OK | X_OK))
			break ;
	}
	if (!tmp[i])
		path = NULL;
	else
		path = ft_strdup(tmp[i]);
	freetab(tmp);
	return (path);
}

int	init(int argc, char **argv, t_pipex *p, char **enpv)
{
	int	i;

	i = 1;
	while (++i <= argc - 2)
		p->c.cmds[i - 2] = initcmd(argv[i]);
	p->f.src = ft_strdup(argv[1]);
	p->f.dst = ft_strdup(argv[argc - 1]);
	p->c.path_cmd[0] = get_bin_path(enpv, *p->c.cmds[0]);
	p->c.path_cmd[1] = get_bin_path(enpv, *p->c.cmds[1]);
	p->f.src_fd = -1;
	p->f.dst_fd = -1;
	p->f.src_fd = open(p->f.src, O_RDONLY, 0644);
	if (p->f.src_fd == -1)
		return (1);
	p->f.dst_fd = open(p->f.dst, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (p->f.dst_fd == -1)
		return (1);
	return (0);
}
