/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_pixel_put_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:23:04 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 10:36:08 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int			mylx_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	char			*dst;

	dst = img->data_addr + x * (img->bits_per_pixel / 8) + y * img->size_line;
	*(unsigned int *)dst = (unsigned int)color;
	return (0);
}
