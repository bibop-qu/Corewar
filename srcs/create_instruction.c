/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:50:30 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/23 14:53:19 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Complete field of instruction element
*/

static void	complet_elem(t_head **head, int index)
{
	t_instruct	*tmp;
	extern t_op	g_op_tab[17];

	tmp = (t_instruct *)(*head)->last->data;
	tmp->op_code = g_op_tab[index].id;
}

/*
**	Create and completed a new elem of instruction
*/

void		create_instruction(t_head **head, int index)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return ;
	if (!(new->data = (t_instruct *)malloc(sizeof(t_instruct))))
		return ;
	new->next = NULL;
	ft_lst_push_back(head, new);
	complet_elem(head, index);
}
