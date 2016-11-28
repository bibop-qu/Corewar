/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:11:36 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/15 14:41:28 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_pop(t_head *head, size_t pos)
{
	t_lst	*current;
	size_t	i;

	current = head->first;
	i = 0;
	if (!head)
		return (NULL);
	while (i < pos)
		current = current->next;
	if (current)
	{
		current->prev = current->next;
		current->next->prev = current->prev;
		current->next = NULL;
		current->prev = NULL;
	}
	return (current);
}
