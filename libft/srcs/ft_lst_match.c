/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:28:59 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/23 18:08:12 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_match(t_head *head, void *data, int (*cmp)(void *, void *))
{
	t_head	*tmp;
	t_head	*new_head;

	tmp = head;
	new_head = head;
	while (tmp)
	{
		if ((*cmp)(tmp->first->data, data))
			ft_lst_push_back(&new_head, ft_lst_create_no_malloc(data));
		tmp->first = tmp->first->next;
	}
	return (new_head->first);
}
