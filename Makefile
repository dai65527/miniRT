# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 08:47:29 by dnakano           #+#    #+#              #
#    Updated: 2020/11/12 08:55:42 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# WHEN USE ON MACOS CHANGE "LINUX" TO "MACOS" (OR SIMPLY COMMENTOUT)
OS				:=	MACOS

CC				:=	gcc
ifeq ($(OS),LINUX)
	CFLAGS		:=	-Wall -Werror -Wextra -D $(OS) #-fsanitize=address
else
	CFLAGS		:=	-Wall -Werror -Wextra #-fsanitize=address
endif
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
					mrt_drawimg_mlx.c \
					mrt_createmlximgs.c \
					mrt_mlxdata_utils.c \
					mrt_drawimg_bmp.c \
					mrt_drawimg_bmp_write.c \
					mrt_drawimg_utils.c \
					mrt_screen_utils.c \
					mrt_mallocscreens.c \
					mrt_raytrace.c \
					mrt_raytrace_calc_reflect.c \
					mrt_color_utils.c \
					mrt_findintersection.c \
					mrt_findintersection_sphere.c \
					mrt_findintersection_plane.c \
					mrt_findintersection_sqr.c \
					mrt_findintersection_cyl.c \
					mrt_findintersection_tgl.c \
					mrt_findintersection_utils.c \
					mrt_errend.c \
					math_vec3_prods.c \
					math_vec3_utils.c \
					math_abs.c \
					mylx_init.c \
					mylx_new_window.c \
					mylx_initmlx.c \
					mylx_new_image_addr.c \
					mylx_pixel_put.c \
					mylx_pixel_put_image.c \
					mylx_put_image_to_window.c \
					mylx_get_screen_size.c \
					mylx_key_hook.c \
					mylx_expose_hook.c \
					mylx_closebtn_hook.c \
					mylx_loop.c \
					mylx_destroy_image.c \
					mylx_destroy_window.c \
					mylx_destroy_display.c
SRCDIR			:=	./srcs
SRCS			:=	$(addprefix $(SRCDIR)/,$(SRCNAME))
OBJNAME			:=	$(SRCNAME:%.c=%.o)
OBJDIR			:=	$(SRCDIR)
OBJS			:=	$(addprefix $(OBJDIR)/,$(OBJNAME))
LIBDIR			:=	./libs
LIBFTDIR		:=	$(LIBDIR)/libft
LIBFTNAME		:=	libft.a
LIBFT			:=	$(LIBFTDIR)/$(LIBFTNAME)
ifeq ($(OS),LINUX)
	LIBNAME		:=	$(LIBFTNAME) libmlx_Linux.a
	LIBS		:=	$(addprefix $(LIBDIR)/,$(LIBNAME))
else
	LIBNAME		:=	$(LIBFTNAME) libmlx.dylib
	LIBS		:=	$(addprefix $(LIBDIR)/,$(LIBNAME))
endif
HEADERNAME		:=	minirt.h libft.h mlx.h
HEADERDIR		:=	./includes
HEADERS			:=	$(addprefix $(HEADERDIR)/,$(HEADERNAME))

.SUFFIXES:		.o .c

.PHONY:			all
all:			$(NAME)

ifeq ($(OS),LINUX)
$(NAME):		$(LIBFT) $(LIBS) $(HEADERS) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) \
				-L$(LIBDIR) $(patsubst lib%,-l%,$(basename $(LIBNAME))) \
				-lXext -lX11 -lm\
				-o $(OUTPUTDIR)/$(NAME)
else
$(NAME):		$(LIBFT) $(LIBS) $(HEADERS) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) \
				-L$(LIBDIR) $(patsubst lib%,-l%,$(basename $(LIBNAME))) \
				-o $(OUTPUTDIR)/$(NAME)
				cp $(LIBDIR)/libmlx.dylib $(OUTPUTDIR)/
endif

$(LIBFT):
				cd $(LIBFTDIR) && make $(LIBFTNAME)
				cp $(LIBFT) $(LIBDIR)

.PHONY:			libft
libft:			$(LIBFT)

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
				rm -f $(OUTPUTDIR)/libmlx.dylib
				rm -f $(OUTPUTDIR)/$(OUTPUTS)

.PHONY:			re
re:				fclean all

.PHONY:			debug
debug:
				$(warning $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)))
				$(warning $(patsubst lib%,-l%,$(basename $(LIBNAME))))
				$(warning $(addprefix $(OUTPUTDIR)/,$(NAME)))
				$(warning $(OUTPUTS))
