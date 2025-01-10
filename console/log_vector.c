/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:03:01 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 21:40:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_vec(char *name, t_vec vec)
{
	printf(CYAN BOLD "---- vec -------------------------\n" RESET);
	printf(UNDERLINE BOLD "%s" RESET "\n", name);
	printf("x:   %f\n", vec.x);
	printf("y:   %f\n", vec.y);
	printf("z:   %f\n", vec.z);
	printf(CYAN BOLD "----------------------------------\n" RESET);
	printf("\n");
}
