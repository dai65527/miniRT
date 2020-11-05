/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:32:23 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 10:29:22 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLX_H
# define MYLX_H

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
int				mylx_key_hook(t_mlx mlx, int (*funct_ptr)(), void *param);
int				mylx_loop(t_mlx mlx);

#endif
