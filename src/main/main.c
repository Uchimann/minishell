/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:52:48 by icelebi           #+#    #+#             */
/*   Updated: 2023/11/02 18:24:30 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_core_sgn *sgn_core;

int	main(int argc, char **argv, char **env)
{
	t_core	*g_core;
	g_core = malloc(sizeof(t_core));
	(void)argc;
	(void)argv;
	sgn_core = (t_core_sgn*)g_core;
	init_core(g_core,env);
	signal(SIGINT,&sig_handler);
	while (1)
	{
		update_loop(g_core);
		g_core->cmd = readline(g_core->title.full_title);
		exit_signal_check(g_core);
		lexer(g_core); // cmd line de herbir bosluk atlanıp kelime öbekleri t_lexlist listesinde lextable da birer düğüm olarak atandı. her düğümün içeriği bir kelime oldu
		expander(g_core); // düğümlerin içlerindeki env değişkenler orjinal hallerine dönüştü yani $USER olan content artık icelebi oldu. contenti NULL olan lexlist node'ları freelendi
		parser(g_core); // 
		executer(g_core);
		update_history(g_core->cmd);
		free_for_loop(g_core);
	}
	free_core(g_core);
}
