/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:56:18 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 18:25:14 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LINUX
# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
#endif

#include "mlx.h"
#include "mylx.h"

int			mylx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	return (mlx_pixel_put(mlx.ptr, mlx.win, x, y, color));
}
