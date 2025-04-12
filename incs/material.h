/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:24:23 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 18:23:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */
typedef struct s_material
{
	t_scaled_col	color;
	double			gloss;
	double			k_specular;
	double			k_diffuse;
	int				checker;
	bool			mirror;
	char			*bump;

	int				line;
	char			*name;
	char			description[256];
}					t_material;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_material			*material_init(t_vec color, t_vec coef);

t_material			*get_material(t_list *list);

#endif