/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylx_new_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:50:39 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/10 19:54:36 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	*mylx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	return (mlx_new_window(mlx_ptr, size_x, size_y, title));
}
