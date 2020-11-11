/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_drawimg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:18:20 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 20:57:26 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int			mrt_drawimg_errend(int mrt_errno, t_scene *scene,
				t_list *screens)
{
	mrt_freescene(scene);
	mrt_freescreens(screens);
	return (mrt_errend(mrt_errno));
}
