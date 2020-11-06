/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:37:08 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 12:11:39 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	justfortest(t_scene *scene, t_list *screens)
{
	int			i, j, k;
	t_screen	*screen;

	(void)scene;
	k = 0;
	while (screens)
	{
		screen = (t_screen *)screens->content;
		i = 0;
		while (i < screen->rez.x)
		{
			j = 0;
			while (j < screen->rez.y)
			{
				screen->px[i][j] = 255 << (8 * (k % 3));
				j++;
			}
			i++;
		}
		screens = screens->next;
		k++;
	}
	return (NOERR);
}

int			mrt_raytrace(t_scene *scene, t_list *screens)
{
	// int		res;
	// t_list	*screens_head;

	justfortest(scene, screens);
	// screens_head = screens;
	// while (screens)
	// {
	// 	res = mrt_raytrace_calc(scene, (t_screen *)(screens->content));
	// 	if (res != NOERR)
	// 		return (res);
	// 	screens = screens->next;
	// }
	return (NOERR);
}
