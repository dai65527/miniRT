/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_light_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 18:45:01 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printlight(void *light_pt)
{
	t_light	*light;

	light = (t_light *)light_pt;
	ft_printf("light pos: [%g, %g, %g]\n",
		light->pos[0], light->pos[1], light->pos[2]);
	ft_printf("brightness ratio: %g\n", light->ratio);
	ft_printf("color: %d\n", light->color);
	ft_printf("\n");
}

int			mrt_readfile_storescene_light(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_light	*light;
	t_light	light_tmp;

	if (!(line = mrt_readfile_readvec(line, light_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &light_tmp.ratio)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &light_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (ERR_MALLOCFAIL);
	*light = light_tmp;
	if (!(newlst = ft_lstnew(light)))
	{
		free(light);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->lights), newlst);
	return (NOERR);
}

int			mrt_readfile_checkscene_light(t_list *lights)
{
	t_light	*light;

	while (lights)
	{
		light = (t_light *)lights->content;
		if (mrt_readfile_checkratio(light->ratio))
			return (ERR_FILEWRONG);
		lights = lights->next;
	}
	return (NOERR);
}
