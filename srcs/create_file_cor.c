/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:09:52 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/22 17:04:26 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Swap int to little edian
*/

static void		swapped(unsigned int *num, unsigned int *size)
{
	unsigned int	swapped;

	swapped = ((*num >> 24) & 0xff) |
	((*num << 8) & 0xff0000) |
	((*num >> 8) & 0xff00) |
	((*num << 24) & 0xff000000);
	*num = swapped;
	*size += 4;
}

/*
**	Initialise header of champ
*/

static void		init_head(t_header *head, unsigned int *size)
{
	ft_bzero(head, sizeof(t_header));
	head->magic = COREWAR_EXEC_MAGIC;
	swapped(&head->magic, size);
	head->prog_size = 0;
	swapped(&head->prog_size, size);
}

/*
**	Write in file all values converted
*/

static void		write_instruction(t_lst *champ, int res_open)
{
	t_lst			*cpy;
	t_header		head;
	int				line;
	unsigned int	size;
	t_order			*label_list;

	cpy = champ;
	line = 0;
	size = 0;
	label_list = NULL;
	init_head(&head, &size);
	while (cpy)
	{
		if (!ft_strncmp(cpy->data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			write_name(cpy->data, &head, &size);
		if (!ft_strncmp(cpy->data, COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)))
			write_comment(cpy->data, &head, &size);
		find_pos_label(cpy->data, &size, &label_list);
		cpy = cpy->next;
	}
	print_header(head, res_open);
}

/*
**	change name to create a writed in file.cor
*/

static char		*change_name(char *file_name)
{
	char	*final_path;
	char	*name;
	char	*extenssion;

	final_path = NULL;
	name = ft_strrchr(file_name, '/');
	file_name = ft_strndup(file_name, name - file_name);
	extenssion = ft_strrchr(name, '.');
	extenssion = ft_strndup(name, extenssion - name);
	name = ft_strjoin(file_name, extenssion);
	final_path = ft_strjoin(name, ".cor");
	free(name);
	free(file_name);
	free(extenssion);
	return (final_path);
}

/*
**	Create, open, call a writen function and close the new file.cor
*/

void			open_new_file(char *file_name, t_head *head, t_order *label_pos)
{
	int		res_open;

	//TODO Modif that !!
	(void)label_pos;
	file_name = change_name(file_name);
	if ((res_open = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0755)) < 0)
		send_id("", 0);
	write_instruction(head->first, res_open);
	if (close(res_open) < 0)
		return ;
}
