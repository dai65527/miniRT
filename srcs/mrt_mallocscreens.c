/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_mallocscreens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:59:29 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 12:30:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

static int	mallocscreens_errend(int mrt_errno, t_list *screens)
{
	mrt_freescreens(screens);
	return (mrt_errno);
}

static int	mallocscreens_errend_free(int mrt_errno, t_screen *screen,
				t_list *screens)
{
	mrt_freescreen(screen);
	mallocscreens_errend(mrt_errno, screens);
	return (mrt_errno);
}

static int	mallocscreens_mallocpx(t_screen *screen)
{
	int		i;
	int		j;

	if (!(screen->px = (int **)malloc(sizeof(int *) * screen->rez.x)))
		return (ERR_MALLOCFAIL);
	i = 0;
	while (i < screen->rez.x)
	{
		if (!(screen->px[i] = (int *)malloc(sizeof(int) * screen->rez.y)))
		{
			j = 0;
			while (j < i)
			{
				free(screen->px[j]);
				j++;
			}
			free(screen->px);
			return (ERR_MALLOCFAIL);
		}
		i++;
	}
	return (NOERR);
}

int			mrt_mallocscreens(t_scene *scene, t_list **screens)
{
	int			i;
	int			res;
	int			n_screens;
	t_screen	*screen;
	t_list		*newlst;

	*screens = NULL;
	n_screens = ft_lstsize(scene->cams);
	i = 0;
	while (i < n_screens)
	{
		if (!(screen = (t_screen *)malloc(sizeof(t_screen))))
			return (mallocscreens_errend(ERR_MALLOCFAIL, *screens));
		screen->rez = *((t_rez *)(scene->rezs->content));
		screen->cam = *((t_cam *)(scene->cams->content));
		scene->cams = scene->cams->next;
		if ((res = mallocscreens_mallocpx(screen)) != NOERR)
			return (mallocscreens_errend(res, *screens));
		if (!(newlst = ft_lstnew(screen)))
			return (mallocscreens_errend_free(ERR_MALLOCFAIL, screen,
				*screens));
		ft_lstadd_back(screens, newlst);
		i++;
	}
	return (NOERR);
}
