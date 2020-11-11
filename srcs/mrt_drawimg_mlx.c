/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_drawimg_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:18:20 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 20:35:52 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int			mrt_drawimg_errend(int mrt_errno, t_scene *scene,
				t_list *screens)
{
	mrt_freescene(scene);
	mrt_freescreens(screens);
	return (mrt_errend(mrt_errno));
}

int			mrt_drawimg_mlx_exit(t_mlxloopparam *param)
{
	mrt_destroymlxdata(param->mlxdata);
	mrt_freescene(param->scene);
	mrt_freescreens(param->screens);
	exit(NOERR);
}

int			mrt_drawimg_mlx_changeimgs(int key, t_mlxloopparam *param)
{
	static int	index_img = 0;

	if (key == KEY_K || key == KEY_RIGHT || key == KEY_UP)
		index_img++;
	else if (key == KEY_J || key == KEY_LEFT || key == KEY_DOWN)
		index_img--;
	else
	{
		if (key == KEY_ESC)
			mrt_drawimg_mlx_exit(param);
		return (0);
	}
	if (index_img < 0)
		index_img = param->mlxdata->num_imgs - 1;
	mylx_put_image_to_window(param->mlxdata->mlx,
		param->mlxdata->imgs[index_img % param->mlxdata->num_imgs], 0, 0);
	return (0);
}

static int		drawimg_mlx_loop(t_mlxdata *mlxdata, t_scene *scene,
				t_list *screens)
{
	t_mlxloopparam	param;

	param.mlxdata = mlxdata;
	param.scene = scene;
	param.screens = screens;
	mylx_key_hook(mlxdata->mlx, mrt_drawimg_mlx_changeimgs, &param);
	mylx_closebtn_hook(mlxdata->mlx, mrt_drawimg_mlx_exit, &param);
	mylx_put_image_to_window(mlxdata->mlx, mlxdata->imgs[0], 0, 0);
	mylx_loop(mlxdata->mlx);
	return (ERR_MLXLOOP);
}

int			mrt_drawimg_mlx(t_scene *scene, t_list *screens)
{
	int				res;
	t_mlxdata		mlxdata;

	if ((res = mrt_initmlxdata(&mlxdata, screens)) != NOERR)
		return (mrt_drawimg_errend(res, scene, screens));
	if ((res = mrt_createmlximgs(&mlxdata, screens)) != NOERR)
		return (mrt_drawimg_errend(res, scene, screens));
	return (drawimg_mlx_loop(&mlxdata, scene, screens));
}
