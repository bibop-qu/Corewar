# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/25 15:08:49 by jealonso          #+#    #+#              #
#    Updated: 2016/11/17 15:14:58 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all re clean fclean cleanlib cleanall fleme

#BINARIES:
CC			= /usr/bin/clang
RM			= /bin/rm
GIT			= /usr/bin/git
MAKE		= /usr/bin/make
MKDIR		= /bin/mkdir

#FILES:
INCPATH		= includes
LFTPATH		= libft
SRCSPATH	= srcs
OBJSPATH	= objs

#FIND:

#LIB:
LIBFT		= $(LFTPATH)/libft.a

#FLAGS:
LDFLAGS		= -L $(LFTPATH)
LDLIBS		= -lft
PATHLIB		= -I $(INCPATH) -I $(LFTPATH)/$(INCPATH)
CFLAGS		= -Wall -Wextra -Werror -g -O0 $(PATHLIB)

#EXECUTALE:
NAME 		= asm

#SRCRS:
SRCS 		= \
			check_content.c \
			debug.c \
			find_prerequis.c \
			main.c \
			message.c \
			op.c \
			size_instruction.c \
			write_header.c \
			create_instruction.c \
			check_flags.c \
			parse_strsep.c \
			arg.c \
			option.c

#OBJ:
OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

#HEAD:
HFILES	= op.h \
		  corewar.h
HEAD	= $(patsubst %.h, $(INCPATH)/%.h, $(HFILES))

all: $(LIBFT) $(OBJSPATH) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C $(LFTPATH) clean
	@$(RM) -rf $(OBJSPATH)
	@echo "Delete current objs files"

fclean: clean
	@$(MAKE) -C $(LFTPATH) fclean
	@$(RM) -rf $(NAME)
	@echo "Delete current objs files and current executable"

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	@$(MKDIR) $@

$(LIBFT):
	@$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "YOUPI"

sup:
	@$(MKDIR) -p ~/Library/Caches/Homebrew
	@$(BREW) rm -rf cmake

test:
	@echo $(OBJS)
	@echo $(HEAD)
