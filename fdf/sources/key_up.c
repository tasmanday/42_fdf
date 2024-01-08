/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:29:03 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:52:40 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	key_up_hook(int keycode, t_data *data)
{
	if (k_u_move_zoom(keycode, data))
		return (0);
	else if (k_u_angles_altitude(keycode, data))
		return (0);
	else if (toggle_lines(keycode, data))
		return (0);
	else if (toggle_rotation(keycode, data))
		return (0);
	else
		return (0);
	return (0);
}

int	k_u_move_zoom(int keycode, t_data *data)
{
	if (keycode == 13)
		data->key_w = 0;
	else if (keycode == 1)
		data->key_s = 0;
	else if (keycode == 0)
		data->key_a = 0;
	else if (keycode == 2)
		data->key_d = 0;
	else if (keycode == 35)
		data->key_p = 0;
	else if (keycode == 37)
		data->key_l = 0;
	else
		return (0);
	return (1);
}

int	k_u_angles_altitude(int keycode, t_data *data)
{
	if (keycode == 32)
		data->key_u = 0;
	else if (keycode == 34)
		data->key_i = 0;
	else if (keycode == 4)
		data->key_h = 0;
	else if (keycode == 38)
		data->key_j = 0;
	else if (keycode == 11)
		data->key_b = 0;
	else if (keycode == 45)
		data->key_n = 0;
	else if (keycode == 43)
		data->key_less = 0;
	else if (keycode == 47)
		data->key_more = 0;
	else
		return (0);
	return (1);
}

int	toggle_lines(int keycode, t_data *data)
{
	if (keycode == 15)
	{
		if (data->is_iso == 0)
			data->is_iso = 1;
		else
			data->is_iso = 0;
	}
	else if (keycode == 17)
	{
		if (data->is_wu == 0)
			data->is_wu = 1;
		else
			data->is_wu = 0;
	}
	else
		return (0);
	return (1);
}

int	toggle_rotation(int keycode, t_data *data)
{
	if (keycode == 31)
	{
		if (data->key_u == 0)
			data->key_u = 1;
		else
			data->key_u = 0;
	}
	else if (keycode == 40)
	{
		if (data->key_h == 0)
			data->key_h = 1;
		else
			data->key_h = 0;
	}
	else if (keycode == 46)
	{
		if (data->key_b == 0)
			data->key_b = 1;
		else
			data->key_b = 0;
	}
	else
		return (0);
	return (1);
}
