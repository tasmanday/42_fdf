/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:43:23 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:52:11 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	to_iso(t_point *pt)
{
	float	orig_x;
	float	orig_y;

	orig_x = pt->x;
	orig_y = pt->y;
	pt->x = (orig_x - orig_y);
	pt->y = (orig_x + orig_y) / 2.0 - pt->z;
}

void	rotate_axis(t_point *pt, t_data *data)
{
	rotate_y(pt, data);
	rotate_x(pt, data);
	rotate_z(pt, data);
}

void	rotate_x(t_point *pt, t_data *data)
{
	float	orig_y;
	float	orig_z;

	orig_y = pt->y;
	orig_z = pt->z;
	pt->y = orig_y * cos(data->x_angle) - orig_z * sin(data->x_angle);
	pt->z = orig_y * sin(data->x_angle) + orig_z * cos(data->x_angle);
}

void	rotate_y(t_point *pt, t_data *data)
{
	float	orig_x;
	float	orig_z;

	orig_x = pt->x;
	orig_z = pt->z;
	pt->x = orig_x * cos(data->y_angle) + orig_z * sin(data->y_angle);
	pt->z = -orig_x * sin(data->y_angle) + orig_z * cos(data->y_angle);
}

void	rotate_z(t_point *pt, t_data *data)
{
	float	orig_x;
	float	orig_y;

	orig_x = pt->x;
	orig_y = pt->y;
	pt->x = orig_x * cos(data->z_angle) - orig_y * sin(data->z_angle);
	pt->y = orig_x * sin(data->z_angle) + orig_y * cos(data->z_angle);
}
