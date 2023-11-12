/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:52:36 by icelebi           #+#    #+#             */
/*   Updated: 2023/10/25 19:52:36 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "tables.h"
# include "macros.h"

//MAIN
void		lexer(t_core *g_core);

//CREATELEXTABLE
void		create_lexlist(t_core *g_core,char *cmdline, t_lexlist **lex_table);
void		parse_cmd(t_core *g_core,char **cmd_line, t_lexlist *last_node);

t_lexlist	*add_new_lex_node(t_lexlist **cmd_table);

size_t		get_quotelen(char *cmd_line);
size_t		get_cmdlen(t_core *g_core, char *cmd_line);

//CLASSIFY
void		classify(t_core *g_core,t_lexlist *lex_table);

//SYNTAXCHECK
void		syntax_check(t_core *g_core);
int			syntax_error_check(t_core *g_core,t_lexlist *lex_list);

int			pipe_error_check(t_core *g_core,t_lexlist *lex_list);
int			run_miss_arg(t_core *g_core,t_lexlist *lex_list);

char		*get_missing_arg(t_core *g_core);
int			read_missing_arg(t_core *g_core,int *fd);
void		read_missing_arg_value(t_core *g_core,int *fd);
int			control_valid_arg(char *ptr);

int			file_error_check(t_core *g_core,t_lexlist *lex_list);

//FREELEXER
void		free_lexer(t_core *g_core);
void		free_lexer_without_heredoc(t_core *g_core,t_lexlist *stop_list);
int			skip_heredoc(t_lexlist **lex, t_lexlist **temp,
				t_lexlist *stop, int *flag);

void		print_lexer(t_core *g_core);

#endif
