/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_createmlximgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:20:39 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 16:42:46 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

static void	createmlximgs_createdata(t_img *img, t_screen *screen,
				int x_max, int y_max)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = screen->rez.x > x_max ? x_max : screen->rez.x;
	y = screen->rez.y > y_max ? y_max : screen->rez.y;
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mylx_pixel_put_to_image(img, i, j, screen->px[i][j]);
			j++;
		}
		i++;
	}
}

static int	createmlximgs_errend(int mrt_errno, t_mlxdata *mlxdata, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		mylx_destroy_image(mlxdata->mlx, mlxdata->imgs[i]);
		i++;
	}
	free(mlxdata->imgs);
	return (mrt_errno);
}

int			mrt_createmlximgs(t_mlxdata *mlxdata, t_list *screens)
{
	int			i;
	t_screen	*screen;

	mlxdata->num_imgs = ft_lstsize(screens);
	if (!(mlxdata->imgs = (t_img *)malloc(sizeof(t_img) * mlxdata->num_imgs)))
		return (ERR_MALLOCFAIL);
	i = 0;
	while (screens)
	{
		screen = (t_screen *)screens->content;
		if (mylx_new_image_addr(mlxdata->mlx, &mlxdata->imgs[i], mlxdata->x, mlxdata->y))
			return (createmlximgs_errend(ERR_MLXIMG, mlxdata, i));
		createmlximgs_createdata(&mlxdata->imgs[i], screen, mlxdata->x, mlxdata->y);
		screens = screens->next;
		i++;
	}
	return (NOERR);
}
