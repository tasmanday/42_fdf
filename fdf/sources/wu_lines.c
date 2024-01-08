/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:38:06 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:53:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	wu_line_hori(t_point start, t_point end, t_delta delta, t_data *data)
{
	t_point	pt;
	float	x;
	int		colour;

	delta.frac_y = start.y;
	x = start.x;
	while (x <= end.x)
	{
		colour = interpolate_colour(start.colour, end.colour, \
		(x - start.x) / delta.dx);
		pt = fill_plot_point(x, (int)delta.frac_y, colour);
		plot(pt, 1 - (delta.frac_y - (int)delta.frac_y), data);
		pt = fill_plot_point(x, (int)delta.frac_y + 1, colour);
		plot(pt, (delta.frac_y - (int)delta.frac_y), data);
		delta.frac_y += delta.slope;
		x++;
	}
}

void	wu_line_vert(t_point start, t_point end, t_delta delta, t_data *data)
{
	delta.frac_x = start.x;
	if (start.y <= end.y)
		wu_line_vpos(start, end, delta, data);
	else
		wu_line_vneg(start, end, delta, data);
}

void	wu_line_vpos(t_point start, t_point end, t_delta delta, t_data *data)
{
	t_point	pt;
	float	y;
	int		colour;

	y = start.y;
	while (y <= end.y)
	{
		colour = interpolate_colour(start.colour, end.colour, \
		(y - start.y) / delta.dy);
		pt = fill_plot_point((int)delta.frac_x, y, colour);
		plot(pt, 1 - (delta.frac_x - (int)delta.frac_x), data);
		pt = fill_plot_point((int)delta.frac_x + 1, y, colour);
		plot(pt, (delta.frac_x - (int)delta.frac_x), data);
		delta.frac_x += delta.slope;
		y++;
	}
}

void	wu_line_vneg(t_point start, t_point end, t_delta delta, t_data *data)
{
	t_point	pt;
	float	y;
	int		colour;

	y = start.y;
	while (y >= end.y)
	{
		colour = interpolate_colour(start.colour, end.colour, \
		(y - start.y) / delta.dy);
		pt = fill_plot_point((int)delta.frac_x, y, colour);
		plot(pt, 1 - (delta.frac_x - (int)delta.frac_x), data);
		pt = fill_plot_point((int)delta.frac_x + 1, y, colour);
		plot(pt, (delta.frac_x - (int)delta.frac_x), data);
		delta.frac_x -= delta.slope;
		y--;
	}
}
