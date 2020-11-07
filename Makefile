# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 08:47:29 by dnakano           #+#    #+#              #
#    Updated: 2020/11/06 22:09:43 by dnakano          ###   ########.fr        #
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
					mrt_renderscene.c \
					mrt_renderscene_mlx.c \
					mrt_createmlximgs.c \
					mrt_mlxdata_utils.c \
					mrt_screen_utils.c \
					mrt_mallocscreens.c \
					mrt_raytrace.c \
					mrt_raytrace_calc.c \
					mrt_raytrace_calc_raytrace.c \
					mrt_color_utils.c \
					mrt_errend.c \
					math_3dvec_utils.c \
					mylx_initmlx.c \
					mylx_new_image_addr.c \
					mylx_pixel_put.c \
					mylx_pixel_put_image.c \
					mylx_put_image_to_window.c \
					mylx_key_hook.c \
					mylx_closebtn_hook.c \
					mylx_loop.c \
					mylx_destroy_image.c \
					mylx_destroy_window.c
SRCDIR			:=	./srcs
SRCS			:=	$(addprefix $(SRCDIR)/,$(SRCNAME))
OBJNAME			:=	$(SRCNAME:%.c=%.o)
OBJDIR			:=	$(SRCDIR)
OBJS			:=	$(addprefix $(OBJDIR)/,$(OBJNAME))
LIBDIR			:=	./libs
LIBFTDIR		:=	$(LIBDIR)/libft
LIBFTNAME		:=	libft.a
LIBFT			:=	$(LIBFTDIR)/$(LIBFTNAME)
LIBNAME			:=	$(LIBFTNAME) libmlx.dylib
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
