/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strsep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:55:43 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/21 18:10:10 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_compare(char c, const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == c)
			return (1);
		++tmp;
	}
	return (0);
}

/*
**	Return ocurence finding, replace the separator char by a '\0'
*/

char		*ft_strsep(char **str, const char *delim)
{
	char	*token;
	char	*begin;

	token = *str;
	begin = token;
	if (!*token)
		return (NULL);
	while (*token && !ft_compare(*token, delim))
		++token;
	if (!*token)
		return (*str);
	*str = token;
	**str = '\0';
	++(*str);
	return (begin);
}
