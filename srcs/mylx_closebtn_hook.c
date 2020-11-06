/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_closebtn_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 08:42:00 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 08:48:13 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int		mylx_closebtn_hook(t_mlx mlx, int (*funct_ptr)(), void *param)
{
	return (mlx_hook(mlx.win, 17, 1 << 17, funct_ptr, param));
}
