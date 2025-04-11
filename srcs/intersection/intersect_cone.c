/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 06:21:34 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

// static t_vec	intersect_cone(t_unit_line ray, const t_cone *cone)
// {
// 	t_vec	roots;

// 	t_vec co; // Vector from the cone's center to the ray origin
// 	t_vec v;  // Ray direction vector
// 	t_vec n;  // Cone's normal vector
// 	double k; // tan(θ)^2
// 	double a, b, c;
// 	v = ray.dir;
// 	n = cone->normal;
// 	co = vec_sub(ray.pos, cone->center);
// 	k = pow(tan(cone->angle), 2);
// 	// Solve quadratic equation for the intersection of the ray and cone
// 	a = vec_dot(v, n) * vec_dot(v, n) - k * vec_dot(v, v);
// 	b = 2 * (vec_dot(v, n) * vec_dot(co, n) - k * vec_dot(v, co));
// 	c = vec_dot(co, n) * vec_dot(co, n) - k * vec_dot(co, co);
// 	roots = solve_eq(a, b, c); // Solve the quadratic equation for roots
// 	return (roots);
// }

// /* CONE */
// t_intersect	is3(t_unit_line ray, void *obj)
// {
// 	t_intersect		is;
// 	const t_cone	*cone = (const t_cone *)obj;
// 	t_vec			roots;
// 	t_pos_vec		p;
// 	double			hit_h;
// 	t_vec			v;
// 	t_vec			temp;
// 	double			k;

// 	k = pow(tan(cone->angle), 2); // tan(θ)^2 for normalizing
// 	is.dist = __DBL_MAX__;
// 	// Initialize the distance to the maximum possible value
// 	roots = intersect_cone(ray, cone); // Get the intersection points
// 	if (roots.x == 0)                  // If no intersection,
// 		return (the initial is structure return (is));
// 	// Use the nearer root (roots.y) to check for the hit point
// 	p = vec_add(ray.pos, vec_mul(ray.dir, roots.y));
// 	// Calculate the intersection point
// 	v = vec_sub(p, cone->center);
// 	// Vector from cone's center to intersection point/
// 	hit_h = vec_dot(v, cone->normal);
// 	// Height of intersection along the cone's axis
// 	if (hit_h > 0 && hit_h < cone->height)
// 	// Check if the intersection is within the cone's height
// 	{
// 		is.dist = roots.y; // Store the distance
// 		is.pos = p;        // Store the intersection position
// 		// Compute the normal at the intersection point
// 		temp = vec_sub(v, vec_mul(cone->normal, hit_h * (1 + k)));
// 		is.normal = vec_normalize(temp); // Normalize the normal vector
// 		is.material = cone->material;    // Store the cone's material
// 	}
// 	else
// 	{
// 		// Check the far side (roots.z)
// 		p = vec_add(ray.pos, vec_mul(ray.dir, roots.z));
// 		// Calculate the intersection point
// 		v = vec_sub(p, cone->center);
// 		// Vector from cone's center to intersection point
// 		hit_h = vec_dot(v, cone->normal);
// 		// Height of intersection along the cone's axis
// 		if (hit_h > 0 && hit_h < cone->height)
// 		// Check if the intersection is within the cone's height
// 		{
// 			is.dist = roots.z; // Store the distance
// 			is.pos = p;        // Store the intersection position
// 			// Compute the normal at the intersection point
// 			temp = vec_sub(v, vec_mul(cone->normal, hit_h * (1 + k)));
// 			is.normal = vec_normalize(temp); // Normalize the normal vector
// 			is.material = cone->material;    // Store the cone's material
// 		}
// 	}
// 	return (is);
// }

t_intersect	is3(t_unit_line ray, void *obj)
{
	const t_cone	*cone = (const t_cone *)obj;
	t_intersect		is;
	t_vec			v;
	t_vec			co;
	double			k;
	double			dv;
	double			cov;
	t_vec			d_minus_vdv;
	t_vec			co_minus_vcov;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			sqrt_disc;
	double			t1;
	double			t2;
	double			t;
	t_vec			hit;
	t_vec			hit_vec;
	double			h;
	t_vec			axis_point;
	t_vec			normal;

	is.dist = __DBL_MAX__;
	v = cone->normal;
	co = vec_sub((t_vec){ray.pos.x - cone->vertex.x, ray.pos.y - cone->vertex.y,
			ray.pos.z - cone->vertex.z}, (t_vec){0, 0, 0});
	k = tan(cone->angle);
	dv = vec_dot(ray.dir, v);
	cov = vec_dot(co, v);
	d_minus_vdv = vec_sub(ray.dir, vec_mul(v, dv));
	co_minus_vcov = vec_sub(co, vec_mul(v, cov));
	a = vec_dot(d_minus_vdv, d_minus_vdv) - k * k * dv * dv;
	b = 2 * (vec_dot(d_minus_vdv, co_minus_vcov) - k * k * dv * cov);
	c = vec_dot(co_minus_vcov, co_minus_vcov) - k * k * cov * cov;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (is);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	t = (t1 > 0) ? t1 : ((t2 > 0) ? t2 : -1);
	if (t < 0)
		return (is);
	hit = vec_add((t_vec){ray.pos.x, ray.pos.y, ray.pos.z}, vec_mul(ray.dir,
				t));
	hit_vec = vec_sub(hit, (t_vec){cone->vertex.x, cone->vertex.y,
			cone->vertex.z});
	h = vec_dot(hit_vec, v);
	if (h < 0 || h > cone->height)
		return (is);
	// 法線の計算
	axis_point = vec_add((t_vec){cone->vertex.x, cone->vertex.y,
			cone->vertex.z}, vec_mul(v, h));
	normal = vec_normalize(vec_sub(hit, axis_point));
	is.pos = (t_pos_vec){hit.x, hit.y, hit.z};
	is.normal = normal;
	is.dist = t;
	is.material = (t_material *)cone->material;
	return (is);
}
