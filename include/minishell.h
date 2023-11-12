/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:16 by stunca            #+#    #+#             */
/*   Updated: 2023/02/19 16:32:33 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include "macros.h"
# include "tables.h"
# include "utilits.h"
# include "lexer.h"
# include "expander.h"
# include "parser.h"
# include "executer.h"
//#include "/usr/include/readline/history.h"

extern t_core_sgn *sgn_core;

//	MAIN
void	init_core(t_core *g_core,char **env);

void	free_for_loop();
void	free_core();

void	update_loop(t_core	*g_core);
void	update_history(char *cmd);
void	update_exec_output(void);

void	sig_handler(int signum);
int		signal_in_reading(t_core_sgn *g_core);
int		signal_while_cmd_works(t_core_sgn *g_core);
void	exit_signal_check(t_core *g_core);

#endif
