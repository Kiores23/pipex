/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:49 by amery             #+#    #+#             */
/*   Updated: 2023/04/03 15:14:18 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;
	int		r;

	if (argc == 1)
		return (1);
	if (argc != 5)
		return (exit_pipex(NULL, 1, "Error"));
	r = init(argc, argv, &p, envp);
	if (r)
		return (exit_pipex(&p, r, "Error"));
	if (pipe_master(&p, envp))
		return (exit_pipex(&p, 3, NULL));
	while (wait(NULL) >= 0)
		;
	return (exit_pipex(&p, 0, NULL));
}
