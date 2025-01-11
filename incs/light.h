#ifndef LIGHT_H
# define LIGHT_H
# include "color.h"
# include "vector.h"
# include <stdbool.h>

# ifndef MAX_LIGHT
#  define MAX_LIGHT 5
# endif

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_light_disc
{
	bool			iscalculated;
	t_unit_vec		light;
	t_unit_vec		reflect;
	t_scaled_col	scol;
}					t_light_disc;

typedef struct s_light
{
	t_pos_vec		pos;
	double			intensity;
	t_scaled_col	color;
	bool			ison;
}					t_light;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_light				*light_init(t_pos_vec pos, t_scaled_col col,
						double intensity, t_sys *sys);
void				light_deinit(t_light *light[], int size);

#endif