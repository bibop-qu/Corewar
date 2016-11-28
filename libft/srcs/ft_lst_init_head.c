/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:35:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/15 14:38:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_head	*ft_lst_init_head(t_head *head, t_lst *elem)
{
	if ((head = (t_head *)malloc(sizeof(t_head))))
		return (NULL);
	else
	{
		if (elem)
			head->size = 1;
		else
			head->size = 0;
		head->first = elem;
		head->last = elem;
	}
	return (head);
}
