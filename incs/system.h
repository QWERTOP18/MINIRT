/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:20:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 09:05:51 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "ft_lst.h"
# include "libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define E_ALLOCATE -1
# define E_MLX_INIT -2
# define E_WINDOW_CREATE -3
# define E_INVALID_INPUT -4

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_objects	t_objects;
typedef struct s_screen		t_screen;

typedef struct s_sys
{
	void					*mlx;
	void					*win;
	t_objects				*obj;
	int						height;
	int						width;
}							t_sys;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_sys						*system_init(void);
void						system_exit(t_sys *sys, int status);

/* ------------------------   eXtend Function   ----------------------------- */

void						*xcalloc(size_t nmemb, size_t size, t_sys *sys);

#endif