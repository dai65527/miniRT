/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_createmlximgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:20:39 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 12:23:35 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

void		mrt_createmlximgs_createdata(t_img *img, t_screen *screen)
{
	int		i;
	int		j;

	i = 0;
	while (i < screen->rez.x)
	{
		j = 0;
		while (j < screen->rez.y)
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
		if (mylx_new_image_addr(mlxdata->mlx, &mlxdata->imgs[i], mlxdata->x, mlxdata->y))
			return (ERR_MLXIMG);
		mrt_createmlximgs_createdata(&mlxdata->imgs[i], screen);
		screens = screens->next;
		i++;
	}
	return (NOERR);
}
