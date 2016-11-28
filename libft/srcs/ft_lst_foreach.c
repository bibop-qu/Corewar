/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:30:27 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/15 14:38:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_foreach(t_head *head, int (*func)(void *))
{
	t_head *tmp;

	tmp = head;
	while (tmp->first)
	{
		if (!(*func)(tmp->first))
			return (0);
		tmp->first = tmp->first->next;
	}
	return (1);
}
