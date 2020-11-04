/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rez_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:53:44 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printrez(void *rez_pt)
{
	t_rez	*rez;

	rez = (t_rez *)rez_pt;
	ft_printf("x: %d\n", rez->size[0]);
	ft_printf("y: %d\n", rez->size[1]);
	ft_printf("\n");
}

int			mrt_readfile_storescene_rez(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_rez	*rez;
	t_rez	rez_tmp;

	if (!(line = mrt_readfile_readint(line, &rez_tmp.size[0])))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readint(line, &rez_tmp.size[1])))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(rez = (t_rez *)malloc(sizeof(t_rez))))
		return (ERR_MALLOCFAIL);
	*rez = rez_tmp;
	if (!(newlst = ft_lstnew(rez)))
	{
		free(rez);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->rezs), newlst);
	return (NOERR);
}
