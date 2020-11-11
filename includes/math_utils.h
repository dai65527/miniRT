/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:16:58 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 08:49:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

void		math_vec3_applylen(double *vec, double len, double *ans);
void		math_vec3_plus(double *a, double *b, double *ans);
void		math_vec3_minus(double *a, double *b, double *ans);
double		math_vec3_norm(double *vec);
void		math_vec3_normalize(double *vec, double *normalizedvec);
double		math_vec3_innerprod(double *a, double *b);
void		math_vec3_outerprod(double *a, double *b, double *ans);

int	    	math_absi(int intnbr);
long    	math_absl(long longnbr);
float   	math_absf(float floatnbr);
double  	math_absd(double doublenbr);

#endif
