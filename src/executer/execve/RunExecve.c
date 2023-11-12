/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunExecve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:34:03 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:34:03 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	run_execve(t_core *g_core,t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	**envlist;

	cmd_node->pid = fork();
	if (!cmd_node->pid)
	{
		create_dup(g_core,cmd_node, fd, fd_index);
		envlist = get_env_cpy(g_core);
		if (execve(cmd_node->cmd, cmd_node->path, envlist) == -1)
		{
			if (cmd_node->cmd)
				print_error("zsh: command not found: ", cmd_node->cmd, "\n");
			free_env_cpy(envlist);
			free_for_loop(g_core);
			free_core(g_core);
			exit(127);
		}
	}
	if (fd && cmd_node->pid)
		clear_pipe(fd);
	waitpid(cmd_node->pid, &g_core->exec_output, 0);
	g_core->exec_output = WEXITSTATUS(g_core->exec_output);
}
