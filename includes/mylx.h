/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:32:23 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 10:20:55 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLX_H
# define MYLX_H

# define KEY_R		15
# define KEY_G		5
# define KEY_B		11
# define KEY_J		38
# define KEY_K		40
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126
# define KEY_ESC	53

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

int				mylx_initmlx(t_mlx *mlx, int x, int y, char *title);
int				mylx_pixel_put(t_mlx mlx, int x, int y, int color);
int				mylx_pixel_put_to_image(t_img *img, int x, int y, int color);
int				mylx_new_image_addr(t_mlx mlx, t_img *img, int x, int y);
int				mylx_put_image_to_window(t_mlx mlx, t_img img, int x, int y);
int				mylx_key_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_closebtn_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_loop(t_mlx mlx);
int				mylx_destroy_window(t_mlx mlx);
int				mylx_destroy_image(t_mlx mlx, t_img img);

#endif