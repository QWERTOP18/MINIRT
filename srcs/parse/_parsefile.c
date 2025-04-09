/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/09 19:15:34 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <system.h>
#include <unistd.h>

/*
 * ※ 以下の定数や各種関数（ft_calloc, ft_lstnew, ft_lstadd_back など）は
 *     プロジェクト内で適切に実装済みであることを前提とします。
 */

/* 定数定義 */
#define BUFF_SIZE 8192  /* 読み込みバッファサイズ */
#define MAX_OBJECTS 100 /* 各要素の最大個数 */

/*
 * ★ パース用の一時構造体（minirt.h の新しい型と区別するため）
 */
typedef struct s_amb_parse
{
	float	ratio;
	int		color[3];
}			t_amb_parse;

typedef struct s_cam_parse
{
	float	pos[3];
	float dir[3]; /* 旧 orient → 新 t_camera では dir とする */
	float	fov;
}			t_cam_parse;

typedef struct s_light_parse
{
	float	pos[3];
	float	brightness;
	int		color[3];
}			t_light_parse;

typedef struct s_sphere_parse
{
	float	center[3];
	float	diameter;
	int		color[3];
}			t_sphere_parse;

typedef struct s_plane_parse
{
	float	point[3];
	float	normal[3];
	int		color[3];
}			t_plane_parse;

typedef struct s_cylinder_parse
{
	float	center[3];
	float	orient[3];
	float	diameter;
	float	height;
	int		color[3];
}			t_cylinder_parse;

/* --- Function Prototypes --- */
void		*update(t_sys *sys);
int			loop_handler(t_sys *sys);
int			my_strcmp(const char *s1, const char *s2);
int			is_space(char c);
char		*get_next_token(char **p);
float		my_atof(const char **s);
int			my_atoi(const char **s);
void		parse_vector3(const char *token, float vec[3]);
void		parse_color(const char *token, int color[3]);
int			has_rt_extension(const char *filename);
void		error_exit(const char *msg);
char		*read_file_content(const char *filename);
void		clean_buffer(char *buffer);

/* ハンドル関数（パース用一時構造体を使用） */
void		handle_ambient(char **p, t_amb_parse *amb);
void		handle_camera(char **p, t_cam_parse *cam);
void		handle_light(char **p, t_light_parse *lt);
void		handle_sphere(char **p, t_sphere_parse *sp);
void		handle_plane(char **p, t_plane_parse *pl);
void		handle_cylinder(char **p, t_cylinder_parse *cy);

/* 既存の generate() 宣言と衝突するため、パーサー関数は generate_from_file() とする */
t_objects	*generate_from_file(t_sys *sys, const char *filename);

/* --- update() と loop_handler() --- */

/* --- ユーティリティ関数 --- */
int	my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r');
}

char	*get_next_token(char **p)
{
	char	*start;

	while (**p && is_space(**p))
		(*p)++;
	if (**p == '\0')
		return (NULL);
	start = *p;
	while (**p && !is_space(**p))
		(*p)++;
	if (**p)
	{
		**p = '\0';
		(*p)++;
	}
	return (start);
}

float	my_atof(const char **s)
{
	int			sign;
	float		result;
	float		frac;
	float		divisor;
	const char	*p = *s;

	sign = 1;
	result = 0;
	frac = 0;
	divisor = 1;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		result = result * 10 + (*p - '0');
		p++;
	}
	if (*p == '.')
	{
		p++;
		while (*p >= '0' && *p <= '9')
		{
			frac = frac * 10 + (*p - '0');
			divisor *= 10;
			p++;
		}
	}
	*s = p;
	return (sign * (result + frac / divisor));
}

int	my_atoi(const char **s)
{
	int			sign;
	int			result;
	const char	*p = *s;

	sign = 1;
	result = 0;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		result = result * 10 + (*p - '0');
		p++;
	}
	*s = p;
	return (sign * result);
}

void	parse_vector3(const char *token, float vec[3])
{
	int			i;
	const char	*p = token;

	for (i = 0; i < 3; i++)
	{
		vec[i] = my_atof(&p);
		/* 入力ファイルによっては範囲チェック不要の場合もあるため、必要ならコメントアウト */
		/* if (vec[i] < -1.0 || vec[i] > 1.0)
			error_exit("Vector value out of range"); */
		if (i < 2)
		{
			if (*p != ',')
				error_exit("Invalid vector format");
			p++; /* カンマをスキップ */
		}
	}
}

void	parse_color(const char *token, int color[3])
{
	int			i;
	const char	*p = token;

	for (i = 0; i < 3; i++)
	{
		color[i] = my_atoi(&p);
		if (color[i] < 0 || color[i] > 255)
			error_exit("Color value out of range");
		if (i < 2)
		{
			if (*p != ',')
				error_exit("Invalid color format");
			p++; /* カンマをスキップ */
		}
	}
}

int	has_rt_extension(const char *filename)
{
	int	i;

	for (i = 0; filename[i] != '\0'; i++)
		;
	if (i < 3)
		return (0);
	if (filename[i - 3] == '.' && filename[i - 2] == 'r' && filename[i
		- 1] == 't')
		return (1);
	return (0);
}

void	error_exit(const char *msg)
{
	printf("Error %s\n", msg);
	exit(1);
}

char	*read_file_content(const char *filename)
{
	char	*buffer;

	int fd, ret, total;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("could not open file");
	buffer = malloc(BUFF_SIZE + 1);
	if (!buffer)
		error_exit("Memory allocation failed");
	total = 0;
	while ((ret = read(fd, buffer + total, BUFF_SIZE - total)) > 0)
		total += ret;
	if (ret < 0)
	{
		perror("Error reading file");
		exit(1);
	}
	buffer[total] = '\0';
	close(fd);
	return (buffer);
}

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n' || buffer[i] == '\r')
			buffer[i] = ' ';
		i++;
	}
}

/* --- ハンドル関数 --- */
void	handle_ambient(char **p, t_amb_parse *amb)
{
	char	*ratio_token;
	char	*color_token;

	ratio_token = get_next_token(p);
	color_token = get_next_token(p);
	if (!ratio_token || !color_token)
		error_exit("Insufficient tokens for Ambient");
	amb->ratio = my_atof((const char **)&ratio_token);
	parse_color(color_token, amb->color);
}

void	handle_camera(char **p, t_cam_parse *cam)
{
	char	*pos_token;
	char	*dir_token;
	char	*fov_token;

	pos_token = get_next_token(p);
	dir_token = get_next_token(p);
	fov_token = get_next_token(p);
	if (!pos_token || !dir_token || !fov_token)
		error_exit("Insufficient tokens for Camera");
	parse_vector3(pos_token, cam->pos);
	parse_vector3(dir_token, cam->dir);
	cam->fov = my_atof((const char **)&fov_token);
}

void	handle_light(char **p, t_light_parse *lt)
{
	char	*pos_token;
	char	*bright_token;
	char	*color_token;

	pos_token = get_next_token(p);
	bright_token = get_next_token(p);
	color_token = get_next_token(p);
	if (!pos_token || !bright_token || !color_token)
		error_exit("Insufficient tokens for Light");
	parse_vector3(pos_token, lt->pos);
	lt->brightness = my_atof((const char **)&bright_token);
	parse_color(color_token, lt->color);
}

void	handle_sphere(char **p, t_sphere_parse *sp)
{
	char	*center_token;
	char	*diameter_token;
	char	*color_token;

	center_token = get_next_token(p);
	diameter_token = get_next_token(p);
	color_token = get_next_token(p);
	if (!center_token || !diameter_token || !color_token)
		error_exit("Insufficient tokens for Sphere");
	parse_vector3(center_token, sp->center);
	sp->diameter = my_atof((const char **)&diameter_token);
	parse_color(color_token, sp->color);
}

void	handle_plane(char **p, t_plane_parse *pl)
{
	char	*point_token;
	char	*normal_token;
	char	*color_token;

	point_token = get_next_token(p);
	normal_token = get_next_token(p);
	color_token = get_next_token(p);
	if (!point_token || !normal_token || !color_token)
		error_exit("Insufficient tokens for Plane");
	parse_vector3(point_token, pl->point);
	parse_vector3(normal_token, pl->normal);
	parse_color(color_token, pl->color);
}

void	handle_cylinder(char **p, t_cylinder_parse *cy)
{
	char	*center_token;
	char	*orient_token;
	char	*diameter_token;
	char	*height_token;
	char	*color_token;

	center_token = get_next_token(p);
	orient_token = get_next_token(p);
	diameter_token = get_next_token(p);
	height_token = get_next_token(p);
	color_token = get_next_token(p);
	if (!center_token || !orient_token || !diameter_token || !height_token
		|| !color_token)
		error_exit("Insufficient tokens for Cylinder");
	parse_vector3(center_token, cy->center);
	parse_vector3(orient_token, cy->orient);
	cy->diameter = my_atof((const char **)&diameter_token);
	cy->height = my_atof((const char **)&height_token);
	parse_color(color_token, cy->color);
}

/* --- generate_from_file() ---
   ファイル内のトークンを読み、各オブジェクトを初期化して t_objects 構造体に詰める */
t_objects	*generate_from_file(t_sys *sys, const char *filename)
{
	t_objects			*objects;
	char				*buffer;
	char				*p;
	char				*token;
	t_amb_parse			amb;
	t_cam_parse			cam;
	t_light_parse		lt;
	t_sphere_parse		sp;
	t_plane_parse		pl;
	t_cylinder_parse	cy;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 0;
	objects->num_of_light = 0;
	objects->id_of_camera = 0;
	objects->objs = NULL;
	buffer = read_file_content(filename);
	clean_buffer(buffer);
	p = buffer;
	while ((token = get_next_token(&p)) != NULL)
	{
		if (my_strcmp(token, "A") == 0)
		{
			handle_ambient(&p, &amb);
			printf("ambient ratio: %f\n", amb.ratio);
			printf("ambient color: %d %d %d\n", amb.color[0], amb.color[1],
				amb.color[2]);
			objects->ambient = vec(amb.color[0] / 255.0 * amb.ratio,
					amb.color[1] / 255.0 * amb.ratio, amb.color[2] / 255.0
					* amb.ratio);
		}
		else if (my_strcmp(token, "C") == 0)
		{
			handle_camera(&p, &cam);
			printf("cam pos: %f %f %f\n", cam.pos[0], cam.pos[1], cam.pos[2]);
			printf("cam dir: %f %f %f\n", cam.dir[0], cam.dir[1], cam.dir[2]);
			printf("cam fov: %f\n", cam.fov);
			objects->camera[objects->num_of_camera] = camera_init(vec(cam.pos[0],
						cam.pos[1], cam.pos[2]), vec(cam.dir[0], cam.dir[1],
						cam.dir[2]), cam.fov, sys);
			objects->num_of_camera++;
		}
		else if (my_strcmp(token, "L") == 0)
		{
			handle_light(&p, &lt);
			printf("light pos: %f %f %f\n", lt.pos[0], lt.pos[1], lt.pos[2]);
			printf("light brightness: %f\n", lt.brightness);
			printf("light color: %d %d %d\n", lt.color[0], lt.color[1],
				lt.color[2]);
			objects->light[objects->num_of_light] = light_init(vec(lt.pos[0],
						lt.pos[1], lt.pos[2]), vec(lt.color[0], lt.color[1],
						lt.color[2]), lt.brightness, sys);
			objects->num_of_light++;
		}
		else if (my_strcmp(token, "sp") == 0)
		{
			handle_sphere(&p, &sp);
			printf("sphere center: %f %f %f\n", sp.center[0], sp.center[1],
				sp.center[2]);
			printf("sphere diameter: %f\n", sp.diameter);
			printf("sphere color: %d %d %d\n", sp.color[0], sp.color[1],
				sp.color[2]);
			ft_lstadd_back(&objects->objs, ft_lstnew(SPHERE,
					sphere_new(vec(sp.center[0], sp.center[1], sp.center[2]),
						sp.diameter, material_init(vec(sp.color[0], sp.color[1],
								sp.color[2])))));
		}
		else if (my_strcmp(token, "pl") == 0)
		{
			handle_plane(&p, &pl);
			ft_lstadd_back(&objects->objs, ft_lstnew(PLANE,
					plane_new(vec(pl.point[0], pl.point[1], pl.point[2]),
						vec(pl.normal[0], pl.normal[1], pl.normal[2]),
						material_init(vec(pl.color[0], pl.color[1],
								pl.color[2])))));
		}
		else if (my_strcmp(token, "cy") == 0)
		{
			handle_cylinder(&p, &cy);
			ft_lstadd_back(&objects->objs, ft_lstnew(CYLINDER,
					cylinder_new(vec(cy.center[0], cy.center[1], cy.center[2]),
						vec(cy.orient[0], cy.orient[1], cy.orient[2]),
						vec(cy.diameter, cy.height, 0),
						material_init(vec(cy.color[0], cy.color[1],
								cy.color[2])))));
		}
		else
			error_exit("Unknown identifier");
	}
	free(buffer);
	return (objects);
}
