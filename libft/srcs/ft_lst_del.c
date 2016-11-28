/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:59:49 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/18 13:34:55 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_head *head)
{
	t_lst	*save;
	t_lst	*current;

	if (!head)
		return ;
	current = head->first;
	while (current)
	{
		save = current;
		current = current->next;
		free(save->data);
		free(save);
	}
	head->first = NULL;
	head->last = NULL;
}
