/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandLexList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:15 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:36:15 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


/*
Bu fonksiyon lextable daki düğümleri tek tek inceliyor. 
her düğümün contentini değiştiriyor. artık düğümler içerisinde
yazdırılmaya ve işlenmeye hazır kelime grupları var.
*/
void	expand_values_from_lexlist(void)
{
	t_lexlist	*lex_table;

	lex_table = g_core.lex_table;
	while (lex_table)
	{
		if (lex_table->type == TEXT) // node'un tipi text ise 
			expand_text(lex_table, 0); // 
		else if (lex_table->next && lex_table->type != SIGN_PIPE) // < > << >>
		{
			if (lex_table->type != SIGN_DOUBLE_LESS) // heredocc değilse ise yani < > ise 
				expand_text(lex_table->next, 1); //
			lex_table = lex_table->next;
		}
		lex_table = lex_table->next;
	}
}


/*
CHAT GPT:

Bu fonksiyon, tek tırnak, çift tırnak, dolar işareti
ve tilde karakterlerini özel olarak işler ve bu karakterlerin 
içeriğini dönüştürür. Meta karakterler (örneğin, > veya <) sonrası
ise sonuçta bir şey üretmemesi gerektiği durumları kontrol eder.
*/

void	expand_text(t_lexlist *lex_table, int is_after_meta) // "$USER", 0 (harf harf ptr ye ekliyoruz)
{
	char	*cmd;
	int		flag;
	char	*ptr;

	cmd = lex_table->content;
	ptr = NULL;
	flag = 0;
	while (*cmd) // node'un contenti NULL olmadığı sürece
	{
		if (*cmd == '\'' && (!flag || flag == 1)) // eğer tek tırnak varsa ve (bayrak 0 veya bayrak 1 ise) yani henüz tırnak içinde değilsek
			flag = flag ^ 1; // bayrağı 1 ile değiştir.  (0 olduğunu varsayarsak)
		else if (*cmd == '\"' && (!flag || flag == 2)) // çift tırnaksa ve (bayrak 0 veya bayrak 2 ise) yani henüz çift tırnak içinde değilsek
			flag = flag ^ 2; // bayrağı 2 ile değiştir.
		else if ((!flag || flag == 2) && (*cmd == *DOLLAR || *cmd == *TILDA)) // ne tek tırnak ne çift tırnaksa ve dollar veya tilda ise
			expand_order(&ptr, &cmd); // cmd line artık node un sonunu gösteriyor. $USER ile gittik R yi gösteren ptr ile geldik. 
		else
			str_addchar(&ptr, *cmd); // hiçbiri değilse ptr'nin gördüğü karakteri cmd yi ekle
		cmd++;
	}
	if (is_after_meta && !ptr) // ptr NULL ise ve after meta 1 ise yani bu bir meta karakter (örneğin, >, <) sonrası işleme tabi tutuluyorsa ve sonuçta bir şey üretilmemişse
		return ;
	free(lex_table->content); // lex table ' daki contenti freele
	lex_table->content = ptr; // yeni contentimiz ptrnin gösterdiği yer olsun (örneğin tırnaklardan kurtulmuş hali var şuan (text ise)) veya $USER ise ptr de icelebi var
}
