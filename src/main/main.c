/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:52:48 by icelebi           #+#    #+#             */
/*   Updated: 2023/10/25 19:52:49 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_core	g_core;

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_core(env);
	signal(SIGINT, &sig_handler);
	while (1)
	{
		update_loop();
		g_core.cmd = readline(g_core.title.full_title);
		exit_signal_check();
		lexer(); // cmd line de herbir bosluk atlanıp kelime öbekleri t_lexlist listesinde lextable da birer düğüm olarak atandı. her düğümün içeriği bir kelime oldu
		expander(); //
		parser();
		executer();
		update_history(g_core.cmd);
		free_for_loop();
	}
	free_core();
}
