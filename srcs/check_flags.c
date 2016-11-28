/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:54:23 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/23 14:55:35 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Check flags when detect FLAG_LABEL but other missing
*/

static int	check_flag_order(unsigned char *flag, int line)
{
	if (!FLAG_C(*flag))
		return (send_id("no_name", line));
	if (!FLAG_N(*flag))
		return (send_id("no_comment", line));
	return (0);
}

/*
**	Find all label and links between them
*/

int			find_label(unsigned char *flag, int line)
{
	if (*flag & FLAG_LABEL && !(FLAG_C(*flag) && FLAG_N(*flag)))
		return (check_flag_order(flag, line));
	return (0);
}
