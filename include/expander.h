/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:52:32 by icelebi           #+#    #+#             */
/*   Updated: 2023/10/25 19:52:32 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "tables.h"
# include "macros.h"

//MAIN
void	expander(t_core *g_core);

//EXANDTEXT
void	expand_values_from_lexlist(t_core *g_core);
void	expand_text(t_core *g_core,t_lexlist *lex_table, int is_after_meta);

void	expand_order(t_core *g_core,char **dst, char **src);
void	expand_envs(t_core *g_core,char **dst, char *ptr);

void	expand_dollar(t_core *g_core,char **dst, char **src);
void	single_dollar(char **dst);
void	double_dollar(t_core *g_core,char **dst, char **src);
void	question_mark(t_core *g_core,char **dst, char **src);
void	expand_dollar_value(t_core *g_core,char **dst, char **src);

void	clear_void_contents(t_core *g_core);
void	brace_check(t_core *g_core, char **dst, char **src);

//EXANDCMD
void	expand_cmd(t_core *g_core,char **dst);
void	expand_from_env_value(char **dst, char *content);
char	*get_arg_from_env_value(char **envs, char *search_arg_name);
char	*get_env(t_core *g_core,char *env_name);

void	print_expander(t_core *g_core);

#endif
