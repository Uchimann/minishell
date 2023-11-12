/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:26 by stunca            #+#    #+#             */
/*   Updated: 2023/02/19 14:45:26 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tables.h"
# include "macros.h"

//MAIN
void		parser(t_core *g_core);

//CREATECMDTABLE
void		create_cmdtable(t_core *g_core,t_lexlist *lex_table);
void		fill_cmdtable_node(t_cmdlist *node);
void		create_cmdtable_nodes(t_core *g_core,int count);

//FILLTABLE
void		fill_cmdtable(t_core *g_core);
void		fill_cmdnode(t_core *g_core,t_cmdlist *node, t_lexlist **lex_list);

char		**create_path(t_lexlist *lex_list);

int			create_new_filelist(t_core *g_core,t_cmdlist *node, t_lexlist **lex_list);
t_filelist	*add_filelist(t_filelist **file_list, char *filename, char *meta);

//CREATEFILES
void		create_files(t_core *g_core,t_cmdlist *node);

void		run_heredocs(t_core *g_core,t_cmdlist *node);
int			read_heredoc(t_core *g_core,t_cmdlist *node, char *eof);
void		set_heredoc_value(t_core *g_core,t_cmdlist *node, int *fd);
void		fill_heredoc(t_core *g_core,char *eof, int *fd);
char		*get_heredoc_values(t_core *g_core,char *eof);
char		*replace_line(t_core *g_core,char *old, char *replace, int begin, int start);
char		*env_check(t_core *g_core,char *line);

void		close_heredoc_file(t_core *g_core);
void		open_heredoc_file(t_core *g_core,char	*create_mode);

void		create_infile(t_core *g_core,t_cmdlist *node, t_filelist *file);

void		create_outfile(t_cmdlist *node, t_filelist *file);

int			check_directory_error(char *file_name);
int			raise_file_error(t_filelist *file, int *file_output);

//FREEPARSER
void		free_parser(t_core *g_core);
void		free_filelist(t_filelist *files);

void		print_files(t_filelist *temp_filelist);
void		print_parser(t_core *g_core);

#endif
