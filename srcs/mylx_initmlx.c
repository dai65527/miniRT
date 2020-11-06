/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_initmlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:09:14 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 21:17:52 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int			mylx_initmlx(t_mlx *mlx, int x, int y, char *title)
{
	if (!(mlx->ptr = mlx_init()))
		return (1);
	if (!(mlx->win = mlx_new_window(mlx->ptr, x, y, title)))
		return (1);
	return (0);
}