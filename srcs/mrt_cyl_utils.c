/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cyl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:43:49 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printcyl(void *cyl_pt)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)cyl_pt;
	ft_printf("center: [%g, %g, %g]\n", cyl->pos[0], cyl->pos[1], cyl->pos[2]);
	ft_printf("orientation: [%g, %g, %g]\n",
		cyl->orien[0], cyl->orien[1], cyl->orien[2]);
	ft_printf("diameter: %g\n", cyl->dia);
	ft_printf("height: %g\n", cyl->hei);
	ft_printf("color: %d\n", cyl->color);
	ft_printf("\n");
}

static int	free_and_return(t_cyl *cyl, int mrt_errno)
{
	free(cyl);
	return (mrt_errno);
}

int			mrt_readfile_storescene_cyl(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_cyl	*cyl;
	t_cyl	cyl_tmp;

	if (!(line = mrt_readfile_readvec(line, cyl_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, cyl_tmp.orien)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &cyl_tmp.dia)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &cyl_tmp.hei)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &cyl_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (ERR_MALLOCFAIL);
	*cyl = cyl_tmp;
	if (!(newlst = ft_lstnew(cyl)))
		return (free_and_return(cyl, ERR_MALLOCFAIL));
	ft_lstadd_back(&(scene->cyls), newlst);
	return (NOERR);
}
