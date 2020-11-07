/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_3dvec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:09:01 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 13:11:39 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void		math_3dvec_applylen(double *vec, double len, double *ans)
{
	ans[0] = len * vec[0];
	ans[1] = len * vec[1];
	ans[2] = len * vec[2];
}

void		math_3dvec_plus(double *a, double *b, double *ans)
{
	ans[0] = a[0] + b[0];
	ans[1] = a[1] + b[1];
	ans[2] = a[2] + b[2];
}

void		math_3dvec_minus(double *a, double *b, double *ans)
{
	ans[0] = a[0] - b[0];
	ans[1] = a[1] - b[1];
	ans[2] = a[2] - b[2];
}

double		math_3dvec_norm(double *vec)
{
	return (sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}

void		math_3dvec_normalize(double *vec, double *normalizedvec)
{
	double	norm;

	norm = math_3dvec_norm(vec);
	normalizedvec[0] = vec[0] / norm;
	normalizedvec[1] = vec[1] / norm;
	normalizedvec[2] = vec[2] / norm;
}

double		math_3dvec_innerprod(double *a, double *b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void		math_3dvec_outerprod(double *a, double *b, double *ans)
{
	ans[0] = a[1] * b[2] - a[2] * b[1];
	ans[1] = a[2] * b[0] - a[0] * b[2];
	ans[2] = a[0] * b[1] - a[1] * b[0];
}
