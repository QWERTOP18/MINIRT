/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:03:01 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 01:21:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_vec(char *name, t_vec vec)
{
	printf(UNDERLINE BLUE BOLD "%s" RESET "\n", name);
	printf("x:  %8.2f\n", vec.x);
	printf("y:  %8.2f\n", vec.y);
	printf("z:  %8.2f\n", vec.z);
	printf("\n");
}
void	log_vec_inline(char *name, t_vec vec)
{
	printf("%s: ", name);
	printf("%8.2f  ", vec.x);
	printf("%8.2f  ", vec.y);
	printf("%8.2f", vec.z);
	printf("\n");
}
