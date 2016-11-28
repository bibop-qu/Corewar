/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:30:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/15 14:37:32 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del_match(t_head *head, void *data, int (*cmp)(void *, void *),
		void (*del)(void *))
{
	t_head	*tmp_head;
	t_lst	*tmp;

	tmp_head = head;
	if (!head)
		return ;
	while (tmp_head->first)
	{
		tmp = tmp_head->first;
		if ((*cmp)(tmp_head->first, data))
		{
			tmp->next = tmp_head->first->next;
			tmp_head->first->next->prev = tmp;
			(*del)(tmp_head);
		}
		tmp_head->first = tmp_head->first->next;
	}
}
