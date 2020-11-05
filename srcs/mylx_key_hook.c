/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:07:15 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 21:11:55 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int			mylx_key_hook(t_mlx mlx, int (*funct_ptr)(), void *param)
{
	return (mlx_key_hook(mlx.win, funct_ptr, param));
}
