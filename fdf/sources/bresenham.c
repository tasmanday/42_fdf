/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:23:17 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:50:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	bresenham(t_point start, t_point end, t_data *data)
{
	t_delta	delta;
	float	x;
	float	y;
	int		i;
	int		colour;

	zoom_and_rotate(&start, data);
	zoom_and_rotate(&end, data);
	delta = calc_t_delta(start, end);
	x = start.x + data->shift_x;
	y = start.y + data->shift_y;
	i = 0;
	while (i <= delta.steps)
	{
		colour = interpolate_colour(start.colour, end.colour, \
		(float)i / delta.steps);
		my_mxl_pixel_put(data, x, y, colour);
		x += delta.x_incr;
		y += delta.y_incr;
		i++;
	}
}

void	zoom_and_rotate(t_point *pt, t_data *data)
{
	pt->x *= data->zoom;
	pt->y *= data->zoom;
	if (data->is_iso)
	{
		rotate_axis(pt, data);
		to_iso(pt);
	}
}

t_delta	calc_t_delta(t_point start, t_point end)
{
	t_delta	delta;

	delta.dx = (int)(end.x - start.x);
	delta.dy = (int)(end.y - start.y);
	delta.steps = fmax(abs(delta.dx), abs(delta.dy));
	delta.x_incr = delta.dx / (float)delta.steps;
	delta.y_incr = delta.dy / (float)delta.steps;
	return (delta);
}
