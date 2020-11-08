/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:37:08 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/08 07:29:14 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			mrt_raytrace(t_scene *scene, t_list *screens)
{
	int		res;
	t_list	*screens_head;

	screens_head = screens;
	while (screens)
	{
		res = mrt_raytrace_calc(scene, (t_screen *)(screens->content));
		if (res != NOERR)
			return (res);
		screens = screens->next;
	}
	return (NOERR);
}
