/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_prods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:09:01 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 08:54:33 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		math_vec3_innerprod(double *a, double *b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void		math_vec3_outerprod(double *a, double *b, double *ans)
{
	ans[0] = a[1] * b[2] - a[2] * b[1];
	ans[1] = a[2] * b[0] - a[0] * b[2];
	ans[2] = a[0] * b[1] - a[1] * b[0];
}
