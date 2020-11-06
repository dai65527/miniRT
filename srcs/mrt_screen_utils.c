/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_screen_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:59:29 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 11:46:16 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

void		mrt_freescreen(void *screen_pt)
{
	int			i;
	t_screen	*screen;

	screen = (t_screen*)screen_pt;
	i = 0;
	while (i < screen->rez.x)
		free(screen->px[i++]);
	free(screen->px);
	free(screen);
}

void		mrt_freescreens(t_list *screens)
{
	ft_lstclear(&screens, mrt_freescreen);
}
