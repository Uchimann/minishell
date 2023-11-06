/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandCmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:35:41 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:35:41 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* CHAT GPT:
expand_cmd fonksiyonu "PATH" çevresel değişkenini arar ve bulur. 
Diyelim ki "PATH" değişkeninin değeri şu şekildedir: 
"/usr/bin:/bin:/usr/sbin"   */

void	expand_cmd(char **dst)
{
	t_env	*temp_env;

	temp_env = g_core.env_table;
	while (temp_env && *dst && **dst)
	{
		if (str_compare("PATH", temp_env->env_name))
		{
			expand_from_env_value(dst, temp_env->content); // lexlistin contenti ile env'nin contenti gidiyor
			return ;
		}
		temp_env = temp_env->next;
	}
}


/* ":" karakterine göre bölümlere ayırır. Yani, "/usr/bin", "/bin" ve "/usr/sbin"
Her bir parça, get_arg_from_env_value fonksiyonu tarafından kontrol edilir.
Örneğin, ilk parça olan "/usr/bin" kontrol edilir.
"ls -l" komutu bu parçayı bulmaya çalışır.
Eğer "/usr/bin/ls" varsa, bu yol geçerli kabul edilir ve control_ptr işaretçisi ile yerine konur.*/


void	expand_from_env_value(char **dst, char *content) // PATH içindeki değerin (/usr/bin:/bin:/usr/sbin) olup olmadığını kontrol eder.
{
	char	*control_ptr;

	while (content && *content)
	{
		control_ptr = get_arg_from_env_value(&content, *dst);
		if (!access(control_ptr, F_OK))
		{
			free(*dst); // lexlistin contenti free'leniyor.
			*dst = control_ptr; // aşağıdan gelen dizin lexlistin contentine atılıyor.
			return ;
		}
		free(control_ptr);
	}
}

char	*get_arg_from_env_value(char **envs, char *search_arg_name) // ":" karakterine göre bölümlere ayırır. Yani, "/usr/bin", "/bin" ve "/usr/sbin"
{
	char	*ptr;
	int		count;
	char	*temp_envs;

	count = 0;
	temp_envs = *envs;
	while (*temp_envs && *temp_envs != ':')
	{
		count++;
		temp_envs++;
		(*envs)++;
	}
	if (!count)
		return (NULL);
	if (**envs)
		(*envs)++;
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	ptr[count] = 0;
	while (--count > -1)
		ptr[count] = *(--temp_envs);
	str_addchar(&ptr, '/');
	own_strjoin(&ptr, search_arg_name);
	return (ptr);
}
