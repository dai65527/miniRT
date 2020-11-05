/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_destroy_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:57:43 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 11:01:11 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mylx.h"

int		mylx_destroy_window(t_mlx mlx)
{
	return (mlx_destroy_window(mlx.ptr, mlx.win));
}
