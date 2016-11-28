/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:44:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/22 14:42:55 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Create a new elem who containt position in program and name to find
*/

t_order		*create_label(unsigned int *size, char *data)
{
	t_order	*new;

	new = NULL;
	if (!(new = (t_order *)malloc(sizeof(t_order))))
		return (NULL);
	new->pos = *size;
	new->label = ft_strdup(data);
	new->next = NULL;
	return (new);
}

/*
**	Push back the new elem
*/

void		push_label(t_order **pos, t_order *new)
{
	t_order	*tmp;

	tmp = *pos;
	if (!pos)
		*pos = new;
	while (tmp)
		tmp = tmp->next;
	tmp->next = new;
}

/*
**	Check if the string finding is a real label or other
*/

static char	*check_is_real(char *str)
{
	char	*tmp;
	char	*find;

	tmp = str;
	find = ft_strchr(str, LABEL_CHAR);
	while (tmp != find)
	{
		if (!ft_isalnum(*tmp) && *tmp != '_')
			return (NULL);
		++tmp;
	}
	return (str);
}

/*
**	Find if line is a label or instruction
*/

void		find_pos_label(char *data, unsigned int *size, t_order **label_pos)
{
	t_order	*new;
	char	*label;

	if (check_is_real(data))
	{
		label = ft_strsep(&data, ":");
		new = create_label(size, label);
		push_label(label_pos, new);
	}
	else
		return ;
}
