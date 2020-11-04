/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_amblight_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:18:36 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:51:56 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printamblight(void *amblight_pt)
{
	t_amblight	*amblight;

	amblight = (t_amblight *)amblight_pt;
	ft_printf("Ratio: %g\n", amblight->ratio);
	ft_printf("Color: %g\n", amblight->ratio);
	ft_printf("\n");
}

int			mrt_readfile_storescene_amblight(const char *line, t_scene *scene)
{
	t_list		*newlst;
	t_amblight	al_tmp;
	t_amblight	*al;

	if (!(line = mrt_readfile_readdouble(line, &(al_tmp.ratio))))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &(al_tmp.color))))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(al = (t_amblight *)malloc(sizeof(t_amblight))))
		return (ERR_MALLOCFAIL);
	*al = al_tmp;
	if (!(newlst = ft_lstnew(al)))
	{
		free(al);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&scene->amblights, newlst);
	return (NOERR);
}
