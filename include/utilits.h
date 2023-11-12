/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:37 by stunca            #+#    #+#             */
/*   Updated: 2023/02/19 14:45:37 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITS_H
# define UTILITS_H

# include "tables.h"
# include "macros.h"

//ENV
void	fill_envs(t_core *g_core,char **env);
t_env	*add_newenv(t_env **env_table, char *env);

char	*get_env_name(char *content);
int		get_env_name_count(char *env_arg);

int		update_env(t_core *g_core,char *env_name, char *new_arg);

char	**get_env_cpy(t_core *g_core);
int		get_env_len(t_core *g_core);
void	free_env_cpy(char **envlist);

int		env_arg_control(t_core *g_core,char *env);

//METACHAR
char	*compare_metachars(t_core *g_core,char *cmd_line);
void	set_metachars(t_core *g_core);

//STR
int		ft_atoi(const char *str);

char	*ft_itoa(int number);
int		get_numbercount(int number);

char	*ft_strdup(char *ptr);

char	*ft_strpcpy(char *dst, char *src, int count);

size_t	ft_strlen(char *ptr);

void	own_strjoin(char **dst, char *src);

void	own_strjoin1(char **dst, char *src);

void	str_addchar(char **dst, char c);

int		get_array_len(char **array);

int		str_compare(char *str1, char *str2);

size_t	trim_spaces(char **cmd_line);

char	*ft_strtonl(char *str);

int		ft_printf(const char *s, ...);

int		ft_putstr_fd_len(char *s, int fd, int len);

char	*ft_strrchr(char *s, int c);

//TITLE
void	set_title(t_core *g_core);
void	change_title(t_core *g_core);

//ERROR
int		print_lex_error(t_core *g_core,t_lexlist *lex_list);
void	print_error(char *ptr1, char *ptr2, char *ptr3);

//FREE
void	free_metachars(t_core *g_core);
void	free_envtable(t_core *g_core);
void	free_title(t_core *g_core);

#endif
