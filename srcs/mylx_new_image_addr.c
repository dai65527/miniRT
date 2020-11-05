/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_new_image_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:47:35 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 10:33:36 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int			mylx_new_image_addr(t_mlx mlx, t_img *img, int x, int y)
{
	if (!(img->ptr = mlx_new_image(mlx.ptr, x, y)))
		return (1);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
											&img->size_line, &img->endian);
	return (0);
}
