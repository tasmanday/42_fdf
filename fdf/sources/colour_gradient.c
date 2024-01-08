/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:44:02 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:50:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	blend_colours(t_value start, t_value end, float f, int *result)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	transparency;

	red = start.r + f * (end.r - start.r);
	green = start.g + f * (end.g - start.g);
	blue = start.b + f * (end.b - start.b);
	transparency = start.t + f * (end.t - start.t);
	*result = create_trgb(transparency, red, green, blue);
}

int	interpolate_colour(int start_colour, int end_colour, float f)
{
	t_value	start_values;
	t_value	end_values;
	int		result;

	start_values = get_all_values(start_colour);
	end_values = get_all_values(end_colour);
	blend_colours(start_values, end_values, f, &result);
	return (result);
}

int	set_point_colour(int x, int y, t_data *data)
{
	int		colour;
	float	f;

	if (data->z_matrix[y][x] == 0)
		return (C_TEAL);
	else if (data->z_matrix[y][x] > 0)
	{
		f = (float)data->z_matrix[y][x] / data->z_max;
		colour = interpolate_colour(C_TEAL, C_ORANGE, f);
		return (colour);
	}
	else
	{
		f = (float)data->z_matrix[y][x] / data->z_min;
		colour = interpolate_colour(C_TEAL, C_PURPLE, f);
		return (colour);
	}
}
