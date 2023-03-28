/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:49 by amery             #+#    #+#             */
/*   Updated: 2023/03/27 20:15:17 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;

	if (argc == 1)
		return (1);
	if (argc < 5)
		return (exit_pipex(NULL, 1, "Arguments"));
	if (!init(argc, argv, &p, envp) || !parsing(p))
		return (exit_pipex(&p, 2, "Arguments"));
	if(pipe_master(p, envp))
		return (exit_pipex(&p, 3, "Pipe"));
	return (exit_pipex(&p, 0, NULL));
}