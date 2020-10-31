# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 08:47:29 by dnakano           #+#    #+#              #
#    Updated: 2020/10/31 20:39:24 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				:=	gcc
CFLAGS			:=	-Wall -Werror -Wextra
NAME			:=	miniRT
OUTPUTDIR		:=	.
OUTPUTS			:=	$(addprefix $(OUTPUTDIR)/,$(NAME))
SRCNAME			:=	minirt.c \
					mrt_errend.c
SRCDIR			:=	./srcs
SRCS			:=	$(addprefix $(SRCDIR)/,$(SRCNAME))
OBJNAME			:=	$(SRCNAME:%.c=%.o)
OBJDIR			:=	$(SRCDIR)
OBJS			:=	$(addprefix $(OBJDIR)/,$(OBJNAME))
LIBDIR			:=	./libs
LIBFTDIR		:=	$(LIBDIR)/libft
LIBFTNAME		:=	libft.a
LIBFT			:=	$(LIBFTDIR)/$(LIBFTNAME)
LIBNAME			:=	$(LIBFTNAME)
LIBS			:=	$(addprefix $(LIBDIR)/,$(LIBNAME))
HEADERNAME		:= minirt.h libft.h mlx.h
HEADERDIR		:= ./includes
HEADERS			:= $(addprefix $(HEADERDIR)/,$(HEADERNAME))

.SUFFIXES:		.o .c

.PHONY:			all
all:			$(NAME)

$(NAME):		$(LIBFT) $(LIBS) $(HEADERS) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) \
				-L$(LIBDIR) $(patsubst lib%,-l%,$(basename $(LIBNAME))) \
				-o $(OUTPUTDIR)/$(NAME)

$(LIBFT):
				cd $(LIBFTDIR) && make $(LIBFTNAME)
				cp $(LIBFT) $(LIBDIR)

.c.o:
				$(CC) $(CFLAGS) -I$(HEADERDIR) \
				-c $< -o $(patsubst %.c,%.o,$<)

.PHONY:			clean
clean:
				cd $(LIBFTDIR)/ && make fclean
				rm -f $(OBJS)

.PHONY:			fclean
fclean:			clean
				cd $(LIBFTDIR)/ && make fclean
				rm -f $(OUTPUTS)

.PHONY:			re
re:				fclean all

.PHONY:			debug
debug:
				$(warning $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)))
				$(warning $(patsubst lib%,-l%,$(basename $(LIBNAME))))
				$(warning $(addprefix $(OUTPUTDIR)/,$(NAME)))
				$(warning $(OUTPUTS))
