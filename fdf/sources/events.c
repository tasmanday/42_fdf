/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:44:54 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:51:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	loop_movement(t_data *data)
{
	loop_move_zoom(data);
	loop_angles_altitude(data);
	update_frame(data);
	return (0);
}

void	loop_move_zoom(t_data *data)
{
	if (data->key_w)
		data->shift_y -= 10;
	if (data->key_s)
		data->shift_y += 10;
	if (data->key_a)
		data->shift_x -= 10;
	if (data->key_d)
		data->shift_x += 10;
	if (data->key_p)
		data->zoom += 2;
	if (data->key_l)
		data->zoom -= 2;
}

void	loop_angles_altitude(t_data *data)
{
	if (data->key_u)
		data->x_angle -= 0.1;
	if (data->key_i)
		data->x_angle += 0.1;
	if (data->key_h)
		data->y_angle -= 0.1;
	if (data->key_j)
		data->y_angle += 0.1;
	if (data->key_b)
		data->z_angle -= 0.1;
	if (data->key_n)
		data->z_angle += 0.1;
	if (data->key_less)
		data->altitude -= 0.01;
	if (data->key_more)
		data->altitude += 0.01;
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	close_button_hook(t_data *data)
{
	close_window(data);
	return (0);
}

/* int	mouse_move_hook(int x, int y, t_data *data)
{
	(void)data;
	printf("mouse position: (%d, %d)\n", x, y);
	return (0);
} */
