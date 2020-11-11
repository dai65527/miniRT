/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_destroy_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:57:43 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 18:24:32 by dnakano          ###   ########.fr       */
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

int		mylx_destroy_window(t_mlx mlx)
{
	return (mlx_destroy_window(mlx.ptr, mlx.win));
}
