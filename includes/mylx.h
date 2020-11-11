/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:32:23 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 23:04:58 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLX_H
# define MYLX_H

# ifdef LINUX
#  define KEY_J		106
#  define KEY_K		107
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_DOWN	65364
#  define KEY_UP	65362
#  define KEY_ESC	65307
# else
#  define KEY_J		38
#  define KEY_K		40
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
#  define KEY_UP	126
#  define KEY_ESC	53
# endif

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
}				t_img;

void			*mylx_init(void);
int				mylx_initmlx(t_mlx *mlx, int x, int y, char *title);
void			*mylx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
int				mylx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				mylx_pixel_put(t_mlx mlx, int x, int y, int color);
int				mylx_pixel_put_to_image(t_img *img, int x, int y, int color);
int				mylx_new_image_addr(t_mlx mlx, t_img *img, int x, int y);
int				mylx_put_image_to_window(t_mlx mlx, t_img img, int x, int y);
int				mylx_key_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_expose_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_closebtn_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_loop(t_mlx mlx);
int				mylx_destroy_window(t_mlx mlx);
int				mylx_destroy_image(t_mlx mlx, t_img img);
int				mylx_destroy_display(t_mlx mlx);

#endif
