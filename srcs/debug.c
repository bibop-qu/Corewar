/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:03:39 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/25 16:29:45 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	TODO Use to debug
*/

void	print_champ_data(t_head *champ)
{
	t_lst	*tmp;

	tmp = champ->first;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}

void	print_content(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		++i;
	}
}
