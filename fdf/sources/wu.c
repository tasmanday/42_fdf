/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:36:16 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:53:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	wu(t_point start, t_point end, t_data *data)
{
	t_delta	delta;

	update_points(&start, &end, data);
	delta.dx = (int)(end.x - start.x);
	delta.dy = (int)(end.y - start.y);
	if (abs(delta.dx) > abs(delta.dy))
	{
		if (delta.dx != 0)
			delta.slope = delta.dy / (float)delta.dx;
		else
			delta.slope = 0.0;
		wu_line_hori(start, end, delta, data);
	}
	else
	{
		if (delta.dy != 0)
			delta.slope = delta.dx / (float)delta.dy;
		else
			delta.slope = 0.0;
		wu_line_vert(start, end, delta, data);
	}
}

void	update_points(t_point *start, t_point *end, t_data *data)
{
	zoom_and_rotate(start, data);
	zoom_and_rotate(end, data);
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
	if (end->x < start->x || (end->x == start->x && end->y < start->y))
		swap_points(start, end);
}

void	swap_points(t_point *start, t_point *end)
{
	t_point	temp_point;

	if (start == NULL || end == NULL)
		return ;
	temp_point = *start;
	*start = *end;
	*end = temp_point;
}

t_point	fill_plot_point(float x, float y, int colour)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.colour = colour;
	return (point);
}

void	plot(t_point pt, float f, t_data *data)
{
	int	blended_colour;

	blended_colour = interpolate_colour(data->background_colour, pt.colour, f);
	my_mxl_pixel_put(data, pt.x, pt.y, blended_colour);
}
