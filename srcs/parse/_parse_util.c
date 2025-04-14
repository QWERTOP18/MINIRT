/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 12:37:46 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	expect_len(int num, char **tokens, int line)
{
	int	i;

	i = 0;
	while (++i < num)
	{
		if (!tokens[i])
		{
			printf("line: %d: Insufficient parameters\n", line);
			return (false);
		}
	}
	if (tokens[i])
	{
		printf("line: %d: too many parameters\n", line);
		return (false);
	}
	return (true);
}

void	deinit_parse_stack(t_sys *sys, t_objects *objects)
{
	camera_deinit(sys->mlx, objects->camera, objects->num_of_camera);
	light_deinit(objects->light, objects->num_of_light);
	free(sys->mlx);
	objs_deinit(objects);
}

int	open_rtfile(const char *file)
{
	int	len;
	int	fd;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 3 || ft_strncmp(file + len - 3, ".rt", 4) != 0)
	{
		write(2, "Error: File must have .rt extension\n", 36);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
	return (fd);
}
