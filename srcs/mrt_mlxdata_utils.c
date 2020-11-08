/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_mlxdata_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:32:00 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 23:00:07 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			mrt_initmlxdata(t_mlxdata *mlxdata, t_list *screens)
{
	mlxdata->x = ((t_screen *)(screens->content))->rez.x;
	mlxdata->y = ((t_screen *)(screens->content))->rez.y;
	mlxdata->imgs = NULL;
	mlxdata->num_imgs = 0;
	if (mylx_initmlx(&mlxdata->mlx, mlxdata->x, mlxdata->y, WINDOWTITLE))
		return (ERR_MLXINIT);
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
	mylx_destroy_window(mlxdata->mlx);
}
