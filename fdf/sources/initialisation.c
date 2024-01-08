/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:56:24 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:51:59 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	data->current_img = 0;
	data->background_colour = C_MIDNIGHT;
	data->zoom = 20.0;
	data->altitude = 0.1;
	data->shift_x = 500;
	data->shift_y = 100;
	data->is_iso = 1;
	data->is_wu = 0;
	data->x_angle = 0.0;
	data->y_angle = 0.0;
	data->z_angle = 0.0;
	data->z_min = INT_MAX;
	data->z_max = INT_MIN;
	data->colour = C_WHITE;
	data->height = 0;
	data->width = 0;
	data->center_x = (data->width * data->zoom) / 2;
	data->center_y = (data->height * data->zoom) / 2;
	init_keys(data);
}

void	init_keys(t_data *data)
{
	data->key_w = 0;
	data->key_s = 0;
	data->key_a = 0;
	data->key_d = 0;
	data->key_p = 0;
	data->key_l = 0;
	data->key_u = 0;
	data->key_i = 0;
	data->key_h = 0;
	data->key_j = 0;
	data->key_b = 0;
	data->key_n = 0;
	data->key_less = 0;
	data->key_more = 0;
}

void	set_z_min_max(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->z_matrix[y][x] < data->z_min)
				data->z_min = data->z_matrix[y][x];
			if (data->z_matrix[y][x] > data->z_max)
				data->z_max = data->z_matrix[y][x];
			x++;
		}
		y++;
	}
}

int	init_img(t_data *data)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		data->img[i].img = mlx_new_image(data->mlx, 1920, 1080);
		if (!data->img[i].img)
		{
			free (data);
			return (-1);
		}
		data->img[i].addr = mlx_get_data_addr(data->img[i].img, \
		&data->img[i].bits_per_pixel, &data->img[i].line_length, \
		&data->img[i].endian);
		i++;
	}
	return (0);
}
