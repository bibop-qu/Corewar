/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:39:59 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/25 16:42:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_read
{
	int				fd;
	char			*content;
	struct s_read	*next;
}					t_read;

typedef struct		s_lst
{
	void			*data;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_head
{
	size_t			size;
	struct s_lst	*first;
	struct s_lst	*last;
}					t_head;

#endif
