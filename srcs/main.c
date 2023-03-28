/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:49 by amery             #+#    #+#             */
/*   Updated: 2023/03/28 19:18:42 by amery            ###   ########.fr       */
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
	int		i;

	if (argc == 1)
		return (1);
	if (argc != 5)
		return (exit_pipex(NULL, 1, "Error"));
	if (!init(argc, argv, &p, envp) || !parsing(p))
		return (exit_pipex(&p, 2, "Error"));
	if(pipe_master(&p, envp))
		return (exit_pipex(&p, 3, "Error pipe"));
	i = 2;
	while (--i >= 0)
	{
		printf("%i\n", p.id[i]);
		waitpid(p.id[i], NULL, WUNTRACED);
	}
	return (exit_pipex(&p, 0, NULL));
}