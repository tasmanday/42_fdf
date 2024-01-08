/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:41:36 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:51:43 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	grid_br(int x, int y, t_data *data)
{
	t_point	start;
	t_point	end;

	start = calc_t_point(x, y, data);
	if (x < data->width - 1)
	{
		end = calc_t_point(x + 1, y, data);
		bresenham(start, end, data);
	}
	if (y < data->height - 1)
	{
		end = calc_t_point(x, y + 1, data);
		bresenham(start, end, data);
	}
	if (x < data->width - 1 && y < data->height - 1)
	{
		end = calc_t_point(x + 1, y + 1, data);
		bresenham(start, end, data);
	}
}

void	grid_wu(int x, int y, t_data *data)
{
	t_point	start;
	t_point	end;

	if (x < data->width - 1)
	{
		start = calc_t_point(x, y, data);
		end = calc_t_point(x + 1, y, data);
		wu(start, end, data);
	}
	if (y < data->height - 1)
	{
		start = calc_t_point(x, y, data);
		end = calc_t_point(x, y + 1, data);
		wu(start, end, data);
	}
	if (x < data->width - 1 && y < data->height - 1)
	{
		start = calc_t_point(x, y, data);
		end = calc_t_point(x + 1, y + 1, data);
		wu(start, end, data);
	}
}

t_point	calc_t_point(int x, int y, t_data *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = (data->z_matrix[y][x]) * (data->zoom * data->altitude);
	point.colour = set_point_colour(x, y, data);
	return (point);
}

void	draw_grid(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->is_wu)
				grid_wu(x, y, data);
			else
				grid_br(x, y, data);
			x++;
		}
		y++;
	}
}
