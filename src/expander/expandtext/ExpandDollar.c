/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandDollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:06 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:36:06 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	expand_dollar(t_core *g_core,char **dst, char **src) // NULL ptr, $ ptr
{
	char	*ptr;

	ptr = (*src) + 1;
	if (*ptr == *DOLLAR)
		double_dollar(g_core,dst, src);
	else if (*ptr == *QUSTION_MARK)
		question_mark(g_core,dst, src);
	else if (*ptr == ' ' || !*ptr || *ptr == *DOUBLE_QUOTE
		|| *ptr == *SINGLE_QUOTE)
		single_dollar(dst);
	else
		expand_dollar_value(g_core,dst, src); 
}

void	single_dollar(char **dst)
{
	str_addchar(dst, *DOLLAR);
}

void	double_dollar(t_core *g_core,char **dst, char **src)
{
	char	*line;

	line = ft_itoa(g_core->old_exec_output);
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	question_mark(t_core *g_core,char **dst, char **src)
{
	char	*line;

	line = ft_itoa(g_core->old_exec_output);
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	expand_dollar_value(t_core *g_core,char **dst, char **src) // NULL ptr $ ptr
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = (*src) + 1;
	if (*ptr == '{')
	{
		brace_check(g_core,dst, src);
		return ;
	}
	while (*ptr != ' ' && *(ptr) && *ptr != *DOUBLE_QUOTE
		&& *ptr != *SINGLE_QUOTE && *ptr != '$') // teyit kontrolü // harf var ise
	{
		count++;
		ptr++;
	}
	ptr = ft_strpcpy(NULL, (*src) + 1, count);
	expand_envs(g_core,dst, ptr);
	free(ptr);
	*src += count;
}
