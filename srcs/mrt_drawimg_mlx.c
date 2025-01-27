/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_drawimg_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:18:20 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 08:39:53 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

static int	drawimg_mlx_exit(t_mlxloopparam *param)
{
	mrt_destroymlxdata(param->mlxdata);
	free(param->mlxdata->mlx.ptr);
	mrt_freescene(param->scene);
	mrt_freescreens(param->screens);
	exit(NOERR);
}

static int	drawimg_mlx_changeimgs(int key, t_mlxloopparam *param)
{
	if (key == KEY_K || key == KEY_RIGHT || key == KEY_UP)
		g_imgindex++;
	else if (key == KEY_J || key == KEY_LEFT || key == KEY_DOWN)
		g_imgindex--;
	else
	{
		if (key == KEY_ESC)
		{
			mrt_destroymlxdata(param->mlxdata);
			mylx_destroy_display(param->mlxdata->mlx);
			free(param->mlxdata->mlx.ptr);
			mrt_freescene(param->scene);
			mrt_freescreens(param->screens);
			exit(NOERR);
		}
		return (0);
	}
	if (g_imgindex < 0)
		g_imgindex = param->mlxdata->num_imgs - 1;
	mylx_put_image_to_window(param->mlxdata->mlx,
		param->mlxdata->imgs[g_imgindex % param->mlxdata->num_imgs], 0, 0);
	return (0);
}

static int	drawimg_mlx_loop(t_mlxdata *mlxdata, t_scene *scene,
					t_list *screens)
{
	t_mlxloopparam	param;

	param.mlxdata = mlxdata;
	param.scene = scene;
	param.screens = screens;
	mylx_key_hook(mlxdata->mlx, drawimg_mlx_changeimgs, &param);
	mylx_closebtn_hook(mlxdata->mlx, drawimg_mlx_exit, &param);
	mylx_put_image_to_window(mlxdata->mlx, mlxdata->imgs[0], 0, 0);
	mylx_loop(mlxdata->mlx);
	return (ERR_MLXLOOP);
}

static int	drawimg_mlx_putimg(t_mlxloopparam *param)
{
	mylx_put_image_to_window(param->mlxdata->mlx,
		param->mlxdata->imgs[g_imgindex % param->mlxdata->num_imgs], 0, 0);
	return (0);
}

int			mrt_drawimg_mlx(t_scene *scene, t_list *screens)
{
	int				res;
	t_mlxdata		mlxdata;
	t_mlxloopparam	param;

	if ((res = mrt_initmlxdata(&mlxdata, screens)) != NOERR)
		return (mrt_drawimg_errend(res, scene, screens));
	if ((res = mrt_createmlximgs(&mlxdata, screens)) != NOERR)
		return (mrt_drawimg_errend(res, scene, screens));
	param.mlxdata = &mlxdata;
	param.scene = scene;
	param.screens = screens;
	mylx_key_hook(mlxdata.mlx, drawimg_mlx_changeimgs, &param);
	mylx_closebtn_hook(mlxdata.mlx, drawimg_mlx_exit, &param);
	mylx_expose_hook(mlxdata.mlx, drawimg_mlx_putimg, &param);
	g_imgindex = 0;
	mylx_loop(mlxdata.mlx);
	return (drawimg_mlx_loop(&mlxdata, scene, screens));
}
