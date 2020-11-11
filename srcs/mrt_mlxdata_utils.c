/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_mlxdata_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:32:00 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 16:39:16 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int			mrt_initmlxdata(t_mlxdata *mlxdata, t_list *screens)
{
	int		screen_x;
	int		screen_y;

	if (!(mlxdata->mlx.ptr = mylx_init()))
		return (ERR_MLXINIT);
	mylx_get_screen_size(mlxdata->mlx.ptr, &screen_x, &screen_y);
	mlxdata->x = ((t_screen *)(screens->content))->rez.x > screen_x
				? screen_x : ((t_screen *)(screens->content))->rez.x;
	mlxdata->y = ((t_screen *)(screens->content))->rez.y > screen_y
				? screen_y : ((t_screen *)(screens->content))->rez.y;
	mlxdata->mlx.win = mylx_new_window(mlxdata->mlx.ptr,
							mlxdata->x, mlxdata->y, WINDOWTITLE);
	mlxdata->imgs = NULL;
	mlxdata->num_imgs = 0;
	return (NOERR);
}

void		mrt_destroymlxdata(t_mlxdata *mlxdata)
{
	int		i;

	i = 0;
	while (i < mlxdata->num_imgs)
	{
		mylx_destroy_image(mlxdata->mlx, mlxdata->imgs[i]);
		i++;
	}
	free(mlxdata->imgs);
	mylx_destroy_window(mlxdata->mlx);
	// free(mlxdata->mlx.ptr);
}
