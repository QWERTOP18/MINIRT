/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:17:33 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 04:53:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

// typedef struct s_material
// {
// 	t_scaled_col	color;
// 	double			gloss;
// 	double			k_specular;
// 	double			k_diffuse;
// 	int				checker;
// 	bool			mirror;
// 	char			*bump;

// 	int				line;
// 	char			*name;
// 	char			description[256];
// }					t_material;

void	log_material(t_material *material)
{
	if (!material)
	{
		printf("Material is NULL\n");
		return ;
	}
	printf(UNDERLINE RED BOLD "material" RESET "\n");
	log_vec_inline("color", material->color);
	printf("gloss: %.2f\n", material->gloss);
	printf("k_specular: %.2f\n", material->k_specular);
	printf("k_diffuse: %.2f\n", material->k_diffuse);
	printf("line: %d\n", material->line);
	if (material->name)
		printf("name: %s\n", material->name);
	if (material->description)
		printf("description: %s\n", material->description);
}

void	log_material_inline(t_material *material)
{
	if (!material)
	{
		printf("Material is NULL\n");
		return ;
	}
	printf("line: %d  ", material->line);
	if (material->name)
		printf("name: %s", material->name);
	printf("\n");
}
