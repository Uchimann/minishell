/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:39:02 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:39:02 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_core(t_core *g_core)
{
	free_metachars(g_core);
	free_envtable(g_core);
	free_title(g_core);
	//rl_clear_history();
}

void	free_for_loop(t_core *g_core)
{
	if (g_core->cmd)
	{
		free(g_core->cmd);
		g_core->cmd = NULL;
	}
	if (g_core->lex_table)
		free_lexer(g_core);
	if (g_core->cmd_table)
		free_parser(g_core);
	close_heredoc_file(g_core);
}
