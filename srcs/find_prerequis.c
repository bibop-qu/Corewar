/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_prerequis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:03:21 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/26 15:18:29 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Compare size of string with flag parametre
*/

static int	size_field(char *str, int line, int flag)
{
	char	*first;
	char	*sec;

	first = NULL;
	sec = NULL;
	first = ft_strchr(str, '"');
	if (++first)
		if ((sec = ft_strchr(first, '"')))
			++sec;
	if (!(first && sec))
		return (send_id("no_quote", line));
	if (sec && (*sec != '\0' && !ft_strchr(COMMENT_CHAR, *sec)))
		return (send_id("syntax", line));
	if ((flag == 1 && (sec - first) > PROG_NAME_LENGTH) ||
			(flag == 2 && (sec - first) > COMMENT_LENGTH))
		return (send_id("error_size", line));
	return (0);
}

/*
**	Check if .comment exist and it size
*/

static int	comment_exist(char *tmp, unsigned char *flag, int line)
{
	if (!ft_strncmp(tmp, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (*flag & FLAG_COMMENT)
			return (send_id("comment", line));
		*flag |= FLAG_COMMENT;
		return (size_field(tmp, line, 2));
	}
	return (0);
}

/*
**	Check if .name exist and it size
*/

static int	name_exist(char *tmp, unsigned char *flag, int line)
{
	if (!ft_strncmp(tmp, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (*flag & FLAG_NAME)
			return (send_id("name", line));
		*flag |= FLAG_NAME;
		return (size_field(tmp, line, 1));
	}
	return (0);
}

/*
**	Find if there are multiple content or name field
*/

int			find_prerequis(char *data, unsigned char *flag, int line)
{
	char	*tmp;
	int		error;

	error = 0;
	tmp = ft_strtrim(data);
	if (*flag & FLAG_LABEL && !(FLAG_C(*flag) || FLAG_N(*flag)))
		++error;
	if (name_exist(tmp, flag, line))
		++error;
	if (comment_exist(tmp, flag, line))
		++error;
	free(tmp);
	return (error);
}
