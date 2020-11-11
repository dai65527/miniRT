/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_destroy_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:23:48 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 19:34:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

#ifdef LINUX

int		mylx_destroy_display(t_mlx mlx)
{
	return (mlx_destroy_display(mlx.ptr));
}

#else

int		mylx_destroy_display(t_mlx mlx)
{
	(void)mlx;
	return (0);
}

#endif
