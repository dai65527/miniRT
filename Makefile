# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 08:47:29 by dnakano           #+#    #+#              #
#    Updated: 2020/11/05 19:07:41 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				:=	gcc
CFLAGS			:=	-Wall -Werror -Wextra
# CFLAGS			:=	-Wall -Werror -Wextra -fsanitize=address
NAME			:=	miniRT
OUTPUTDIR		:=	.
OUTPUTS			:=	$(addprefix $(OUTPUTDIR)/,$(NAME))
SRCNAME			:=	minirt.c \
					mrt_amblight_utils.c \
					mrt_readfile.c \
					mrt_readfile_read.c \
					mrt_readfile_storescene.c \
					mrt_readfile_utils.c \
					mrt_readfile_checkscene.c \
					mrt_scene_utils.c \
					mrt_cam_utils.c \
					mrt_cyl_utils.c \
					mrt_light_utils.c \
					mrt_plane_utils.c \
					mrt_rez_utils.c \
					mrt_sphere_utils.c \
					mrt_sqr_utils.c \
					mrt_tgl_utils.c \
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
HEADERNAME		:=	minirt.h libft.h mlx.h
HEADERDIR		:=	./includes
HEADERS			:=	$(addprefix $(HEADERDIR)/,$(HEADERNAME))

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
