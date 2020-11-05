/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_destroy_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:04:02 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 11:05:45 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int		mylx_destroy_image(t_mlx mlx, t_img img)
{
	return (mlx_destroy_image(mlx.ptr, img.ptr));
}
