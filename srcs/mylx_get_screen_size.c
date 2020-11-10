/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_get_screen_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:04:28 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/10 20:08:40 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		mylx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	return (mlx_get_screen_size(mlx_ptr, sizex, sizey));
}
