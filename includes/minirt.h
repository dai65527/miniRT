/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:13:19 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 09:04:38 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include "libft.h"
# include "mylx.h"

# define FLG_BMP	1

# define NOERR			0x0000
# define ERR_ARGC		0x0001
# define ERR_OPT		0x0002
# define ERR_MALLOCFAIL	0x0003
# define ERR_FILETYPE	0x0101
# define ERR_FILEOPEN	0x0102
# define ERR_FILEREAD	0x0103
# define ERR_FILEWRONG	0x0104
# define ERR_MLXINIT	0x1001
# define ERR_MLXIMG		0x1002
# define ERR_MLXLOOP	0x1003

/*
** configuration
*/
# define WINDOWTITLE		"miniRT"
# define MRT_EPSIRON		1.0e-10
# define SPECREFLEC_FACTOR	1.0
# define SHININESS			20.0

int				g_flgs;

typedef struct	s_scene
{
	t_list		*rezs;
	t_list		*amblights;
	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*sqrs;
	t_list		*cyls;
	t_list		*tgls;
}				t_scene;

typedef struct	s_rez
{
	int			x;
	int			y;
}				t_rez;

typedef struct	s_amblight
{
	double		ratio;
	int			color;
}				t_amblight;

typedef struct	s_cam
{
	double		pos[3];
	double		orien[3];
	double		fov;
}				t_cam;

typedef struct	s_light
{
	double		pos[3];
	double		ratio;
	int			color;
}				t_light;

typedef struct	s_sphere
{
	double		pos[3];
	double		dia;
	int			color;
}				t_sphere;

typedef struct	s_plane
{
	double		pos[3];
	double		orien[3];
	int			color;
}				t_plane;

typedef struct	s_sqr
{
	double		pos[3];
	double		orien[3];
	double		size;
	int			color;
}				t_sqr;

typedef struct	s_cyl
{
	double		pos[3];
	double		orien[3];
	double		dia;
	double		hei;
	int			color;
}				t_cyl;

typedef struct	s_tgl
{
	double		pos1[3];
	double		pos2[3];
	double		pos3[3];
	int			color;
}				t_tgl;

typedef struct	s_ray
{
	double		*orig;
	double		dir[3];
}				t_ray;

typedef struct	s_screen
{
	t_cam		cam;
	t_rez		rez;
	int			**px;
	double		unitvec_x[3];
	double		unitvec_y[3];
	double		dist;
}				t_screen;

typedef struct	s_mlxdata
{
	t_mlx		mlx;
	t_img		*imgs;
	int			num_imgs;
	int			x;
	int			y;
}				t_mlxdata;

typedef struct	s_mlxloopparam
{
	t_mlxdata	*mlxdata;
	t_scene		*scene;
	t_list		*screens;
}				t_mlxloopparam;

typedef struct	s_surface
{
	double		pos[3];
	double		normvec[3];
	int			color;
	double		dist;
}				t_surface;

void			mrt_initscene(t_scene *scene);
void			mrt_freescene(t_scene *scene);

int				mrt_errend(int mrt_errno);

int				mrt_readfile(const char *path, t_scene *scene);

int				mrt_readfile_storescene(const char *line, t_scene *scene);
int				mrt_readfile_storescene_rez(const char *line, t_scene *scene);
int				mrt_readfile_storescene_amblight(const char *line,
					t_scene *scene);
int				mrt_readfile_storescene_cam(const char *line, t_scene *scene);
int				mrt_readfile_storescene_light(const char *line, t_scene *scene);
int				mrt_readfile_storescene_sphere(const char *line,
					t_scene *scene);
int				mrt_readfile_storescene_plane(const char *line, t_scene *scene);
int				mrt_readfile_storescene_sqr(const char *line, t_scene *scene);
int				mrt_readfile_storescene_cyl(const char *line, t_scene *scene);
int				mrt_readfile_storescene_tgl(const char *line, t_scene *scene);

const char		*mrt_readfile_readint(const char *line, int *n);
const char		*mrt_readfile_readdouble(const char *line, double *n);
const char		*mrt_readfile_readvec(const char *line, double *vec);
const char		*mrt_readfile_readcolor(const char *line, int *color);

int				mrt_readfile_checkscene(t_scene *scene);
int				mrt_readfile_checkratio(double ratio);	
int				mrt_readfile_checknormorien(double *vec);
int				mrt_readfile_checkscene_rez(t_list *rezs);
int				mrt_readfile_checkscene_amblight(t_list *amblights);
int				mrt_readfile_checkscene_cam(t_list *cams);
int				mrt_readfile_checkscene_light(t_list *lights);
int				mrt_readfile_checkscene_sphere(t_list *spheres);
int				mrt_readfile_checkscene_plane(t_list *planes);
int				mrt_readfile_checkscene_sqr(t_list *sqrs);
int				mrt_readfile_checkscene_cyl(t_list *cyls);
int				mrt_readfile_checkscene_tgl(t_list *tgls);

int				mrt_readfile_isrt(const char *path);
int				mrt_readfile_checkendl(const char *line);
int				mrt_readfile_errend(int err, t_scene *scene, char *line,
					int fd);

void			mrt_printscene(t_scene scene);
void			mrt_printrez(void *rez_pt);
void			mrt_printamblight(void *amblight_pt);
void			mrt_printcam(void *cam_pt);
void			mrt_printlight(void *light_pt);
void			mrt_printsphere(void *sphere_pt);
void			mrt_printplane(void *plane_pt);
void			mrt_printsqr(void *sqr_pt);
void			mrt_printcyl(void *cyl_pt);
void			mrt_printtgl(void *tgl_pt);

int				mrt_mallocscreens(t_scene *scene, t_list **screens);
void			mrt_freescreens(t_list *screens);
void			mrt_freescreen(void *screen_pt);

int				mrt_renderscene(t_scene *scene);
int				mrt_raytrace(t_scene *scene, t_list *screens);
int				mrt_raytrace_calc(t_scene *scene, t_screen *screen);
int				mrt_raytrace_calc_raytrace(t_ray *ray, t_scene *scene);
int				mrt_raytrace_calc_reflect(t_ray *ray, t_surface *surface, t_scene *scene);

int				mrt_color_apply_brightness(int color, double ratio);
void			mrt_color_int_to_vec(int color, double *color_vec);
int				mrt_color_vec_to_int(double *color_vec);

int				mrt_renderscene_mlx(t_scene *scene, t_list *screens);
int				mrt_renderscene_mlx_loop(t_mlxdata *mlxdata, t_scene *scene,
					t_list *screens);
int				mrt_renderscene_mlx_changeimgs(int key, t_mlxloopparam *param);
int				mrt_renderscene_mlx_exit(t_mlxloopparam *param);
int				mrt_renderscene_errend(int mrt_errno, t_scene *scene,
					t_list *screens);

t_surface		mrt_findintersection(t_ray *ray, t_scene *scene);
t_surface		mrt_findintersection_sphere(t_ray *ray, t_list *spheres);
t_surface		mrt_findintersection_plane(t_ray *ray, t_list *planes);
t_surface		mrt_findintersection_plane_solve(t_ray *ray, t_plane *plane);
t_surface		mrt_findintersection_sqr(t_ray *ray, t_list *sqrs);
int				mrt_isinepsilon(double var);
int				mrt_surface_isnearer(t_surface old, t_surface new);

int				mrt_createmlximgs(t_mlxdata *mlxdata, t_list *screens);
void			mrt_createmlximgs_createdata(t_img *img, t_screen *screen);

int				mrt_initmlxdata(t_mlxdata *mlxdata, t_list *screens);
void			mrt_destroymlxdata(t_mlxdata *mlxdata);

#endif
