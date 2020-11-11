/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_createmlximgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:20:39 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 08:16:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

static void	mrt_createmlximgs_createdata(t_img *img, t_screen *screen,
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

int			mrt_createmlximgs(t_mlxdata *mlxdata, t_list *screens)
{
	int			i;
	t_list		*lstorigin;
	t_screen	*screen;

	mlxdata->num_imgs = ft_lstsize(screens);
	if (!(mlxdata->imgs = (t_img *)malloc(sizeof(t_img) * mlxdata->num_imgs)))
		return (ERR_MALLOCFAIL);
	lstorigin = screens;
	i = 0;
	while (screens)
	{
		screen = (t_screen *)screens->content;
		/// screen and list should be freed when error
		if (mylx_new_image_addr(mlxdata->mlx, &mlxdata->imgs[i], mlxdata->x, mlxdata->y))
			return (ERR_MLXIMG);
		mrt_createmlximgs_createdata(&mlxdata->imgs[i], screen, mlxdata->x, mlxdata->y);
		screens = screens->next;
		i++;
	}
	return (NOERR);
}
