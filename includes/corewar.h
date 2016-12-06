/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corware.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/23 14:56:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>

/*
**	TODO To delete after tests because used to printf function
*/

# include <stdio.h>

/*
**	Use for define size of errors message in (t_mess)
*/

# define INDEX			20

/*
**	Use to find if fiels exist and their formats
*/

# define FLAG_NAME		1
# define FLAG_COMMENT	2
# define FLAG_LABEL		4

/*
**	Macro for economized lines
*/

# define FLAG_N(flag)	(flag & FLAG_NAME)
# define FLAG_C(flag)	(flag & FLAG_COMMENT)

/*
** Global variable for option -a
*/

int option;

/*
**	Define a strusture who contain all error massage
*/

typedef struct			s_mess
{
	char				*key_word;
	char				*message;
}						t_mess;

typedef struct			s_order
{
	unsigned int		pos;
	char				*label;
	struct s_order		*next;
}						t_order;

typedef struct			s_instruct
{
	int					op_code;
	int					**arg_type;
	int					**arg_value;
	struct s_instruct	*next;
}						t_instruct;

/*
**	Struct to economized lines in check_content.c
*/

typedef struct			s_posandflag
{
	int					line;
	unsigned int		pos;
	unsigned char		flag;
}						t_posandflag;

int						print_message(int i);
int						print_message_line(int i, int line);
int						send_id(char *str, int line);
int						error_read(t_head *files);
int						check_content(t_lst *champ, char *file_name);
int						find_prerequis(char *data, unsigned char *flag,
		int line);
void					open_new_file(char *file_name, t_head *head,
		t_order *label_pos);
void					write_name(char *data, t_header *head,
		unsigned int *size);
void					write_comment(char *data, t_header *head,
		unsigned int *size);
void					find_pos_label(char *data, unsigned int *size,
		t_order **pos);
char					*ft_strsep(char **str, const char *delim);
void					print_header(t_header head, int res_open);
void					create_instruction(t_head **head, int index);
int						find_label(unsigned char *flag, int line);
int						define_type(char *str);
char	*ft_strcut(char *str);

/*
**	Use to debuging in debug.c
*/

void					print_champ_data(t_head *champ);
void					print_content(char **tab);
void					print_option(char *file_name);

#endif
