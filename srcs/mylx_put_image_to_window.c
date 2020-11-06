/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_put_image_to_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:08:50 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 09:11:42 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int			mylx_put_image_to_window(t_mlx mlx, t_img img, int x, int y)
{
	return (mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, x, y));
}
