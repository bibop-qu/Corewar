/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:26:20 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/02 14:52:06 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Contains all variable message
*/

const t_mess g_usage_tab[INDEX] =
{
	{"empty", ""},
	{"file", "File.s"},
	{"usage", "Usage : ./asm [-a] <file.s>"},
	{"open", "Error : can't open file"},
	{"close", "Error : can't close file"},
	{"no_malloc_head", "Error : can't allocate size for a champion"},
	{"no_malloc_link", "Error : can't allocate size for a new link"},
	{"no_malloc_data", "Error : can't allocate size to copy instruction"},
	{"head&champ", "Error : They are no champions and no head of list"},
	{"no_malloc_struct", "Error : can't allocate size for t_content"},
	{"error_size", "Error : size of field is too big"},
	{"name", "File content two name"},
	{"comment", "File content two comment"},
	{"label", "Poorly positioned instruction"},
	{"no_quote", "they are no quote"},
	{"syntax", "Syntax error"},
	{"no_name", ".name field are missing"},
	{"no_comment", ".comment field are missing"},
	{"", "Error"},
	{NULL, "String error doesn't exist try another"}
};

/*
**	Find a key_word for send to print_messge function
*/

int	send_id(char *str, int line)
{
	int	i;

	i = 0;
	while (g_usage_tab[i].key_word && i < INDEX)
	{
		if (!ft_strcmp(g_usage_tab[i].key_word, str))
		{
			if (line < 0)
				return (print_message(i));
			else
				return (print_message_line(i, line));
		}
		++i;
	}
	if (!g_usage_tab[i].key_word)
		return (print_message(i));
	return (print_message(i));
}

/*
** Check if file_name_terminate by .s
*/

int	compatible_file(char *str)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = ft_strlen(str);
	if (i < 3)
		return (print_message(0));
	else
	{
		tmp = i - 2;
		while (tmp < i)
		{
			if (str[tmp] != g_usage_tab[i].key_word[2])
				return (1);
		}
	}
	return (0);
}

/*
**	Print error with line
*/

int	print_message_line(int i, int line)
{
	ft_putstr_fd(g_usage_tab[i].message, 2);
	ft_putstr_fd(" [line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd("]\n", 2);
	return (1);
}

/*
**	Print all error according to id message
*/

int	print_message(int i)
{
	ft_putendl_fd(g_usage_tab[i].message, 2);
	return (1);
}
